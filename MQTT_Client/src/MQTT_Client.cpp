/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#include "../include/MQTT_Client.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <winsock2.h>

#include "../include/ConnectionUnencrypted.h"

#pragma comment(lib,"WS2_32")

namespace MQTT_Client_NS
{

    bool MQTT_Client::spinOnce()
	{
		bool result = false;
		MQTT_Data_t data;
		bool dataReceived = false;

		dataReceived = true;
		if(dataReceived)
		{
			data.data = "MQTT spin once data";
			data.topic = "testTopic_2137";
			data.dataType = MQTT_Client::MQTT_Data_t::data_t::TEXT;

			if(callback==nullptr)
				return false;

			result = (*callback)(data);
		}

		return result;
	}

    bool MQTT_Client::spin()
	{
		try
		{			
			while( spinOnce() );
		}
		catch(const std::exception& e)
		{

		}		

		return false;
	}

	bool MQTT_Client::setConnectionType(std::string type)
	{
		if(connection!=nullptr)
		{
			connection->disconnect();
			delete connection;
			connection = (Connection*)nullptr;
		}

		if( 0==type.compare("unencrypted") )
			connection = new ConnectionUnencrypted();
		
		return connection != nullptr;
	}

	void MQTT_Client::setCallback( callback_t callback_ )
	{
		callback = callback_;
	}

	void MQTT_Client::setPort(port_t port_)
	{
		port = port_;
	}

	void MQTT_Client::setAddress(address_t& address_)
	{
		address = address_;
	}

	void MQTT_Client::setAddress(const char* address_)
	{
		address = address_t(address_);
	}


	bool MQTT_Client::connect()
	{
		WSADATA wsaData;

		int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != NO_ERROR)
			printf("Initialization error.\n");

		SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (mainSocket == INVALID_SOCKET)
		{
			printf("Error creating socket: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		sockaddr_in service;
		memset(&service, 0, sizeof(service));
		service.sin_family = AF_INET;
		service.sin_addr.s_addr = inet_addr("127.0.0.1");
		service.sin_port = htons(27015);

		if (::connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
		{
			printf("Failed to connect.\n");
			WSACleanup();
			return 1;
		}


		// najpierw tworzymy socket i łaczmy się do niego 
		/*struct addrinfo *result = NULL;
		struct addrinfo *ptr = NULL;
		struct addrinfo hints;
		int iResult = 0;
		int sock = 0;

		// Resolve the server address and port
//		iResult = getaddrinfo(argv[1], port, &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		SOCKET ConnectSocket = INVALID_SOCKET;
		ptr = result;
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

		if (ConnectSocket == INVALID_SOCKET) {
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			return 1;
		}

		// Create a socket
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0)
		{
			printf("\n Socket creation error \n");
			freeaddrinfo(result);
			WSACleanup();
			return false;
		}

		// Connect to server.
//		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen); // to kojarzy z naszym connect trzeba to zmienic
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
		}*/

		return true;
	}

	void MQTT_Client::disconnect()
	{

	}
	
	bool MQTT_Client::subscribe(std::string& topic)
	{
		return false;
	}

	bool MQTT_Client::subscribe(const char* topic_)
	{
		std::string topic(topic_);
		return subscribe(topic);
	}

	bool MQTT_Client::unsubscribe(std::string& topic_)
	{
		return false;
	}

	bool MQTT_Client::unsubscribe(const char* topic_)
	{
		std::string topic(topic_);
		return unsubscribe(topic);
	}

	bool MQTT_Client::publish(std::string& topic_, MQTT_Data_t& data)
	{
		return false;
	}

	bool MQTT_Client::publish(const char* topic_, MQTT_Data_t& data)
	{
		std::string topic(topic_);
		return publish(topic, data);
	}

	MQTT_Client::MQTT_Client()
	{
		connection = (Connection*)nullptr;
		callback = nullptr;
		port = 0;
		address = "";
	}

	MQTT_Client::~MQTT_Client()
	{
		if (connection != nullptr)
			delete connection;
	}


	//######################################################
	// mosquitto od Doliego 

	int mosquitto_subscribe_callback(
		int(*callback)(struct mosquitto *, void *, const struct mosquitto_message *),
		void *userdata,
		const char *topic,
		int qos,
		const char *host,
		int port,
		const char *client_id,
		int keepalive,
		bool clean_session,
		const char *username,
		const char *password,
		const struct libmosquitto_will *will,
		const struct libmosquitto_tls *tls)
	{
		struct mosquitto *mosq;
		struct userdata__callback cb_userdata;
		int rc;

		if (!callback || !topic) {
			return MOSQ_ERR_INVAL;
		}

		cb_userdata.topic = topic;
		cb_userdata.qos = qos;
		cb_userdata.rc = 0;
		cb_userdata.userdata = userdata;
		cb_userdata.callback = callback;

		mosq = mosquitto_new(client_id, clean_session, &cb_userdata);
		if (!mosq) {
			return MOSQ_ERR_NOMEM;
		}

		if (will) {
			rc = mosquitto_will_set(mosq, will->topic, will->payloadlen, will->payload, will->qos, will->retain);
			if (rc) {
				mosquitto_destroy(mosq);
				return rc;
			}
		}
		if (username) {
			rc = mosquitto_username_pw_set(mosq, username, password);
			if (rc) {
				mosquitto_destroy(mosq);
				return rc;
			}
		}
		if (tls) {
			rc = mosquitto_tls_set(mosq, tls->cafile, tls->capath, tls->certfile, tls->keyfile, tls->pw_callback);
			if (rc) {
				mosquitto_destroy(mosq);
				return rc;
			}
			rc = mosquitto_tls_opts_set(mosq, tls->cert_reqs, tls->tls_version, tls->ciphers);
			if (rc) {
				mosquitto_destroy(mosq);
				return rc;
			}
		}

		mosquitto_connect_callback_set(mosq, on_connect);
		mosquitto_message_callback_set(mosq, on_message_callback);

		rc = mosquitto_connect(mosq, host, port, keepalive);
		if (rc) {
			mosquitto_destroy(mosq);
			return rc;
		}
		rc = mosquitto_loop_forever(mosq, -1, 1);
		mosquitto_destroy(mosq);
		if (cb_userdata.rc) {
			rc = cb_userdata.rc;
		}
		//if(!rc && cb_userdata.max_msg_count == 0){
			//return MOSQ_ERR_SUCCESS;
		//}else{
			//return rc;
		//}
		return MOSQ_ERR_SUCCESS;
	}

	int mosquitto_subscribe_simple(
		struct mosquitto_message **messages,
		int msg_count,
		bool want_retained,
		const char *topic,
		int qos,
		const char *host,
		int port,
		const char *client_id,
		int keepalive,
		bool clean_session,
		const char *username,
		const char *password,
		const struct libmosquitto_will *will,
		const struct libmosquitto_tls *tls)
	{
		struct userdata__simple userdata;
		int rc;
		int i;

		if (!topic || msg_count < 1 || !messages) {
			return MOSQ_ERR_INVAL;
		}

		*messages = NULL;

		userdata.messages = (mosquitto_message*)calloc(sizeof(struct mosquitto_message), msg_count);
		if (!userdata.messages) {
			return MOSQ_ERR_NOMEM;
		}
		userdata.message_count = 0;
		userdata.max_msg_count = msg_count;
		userdata.want_retained = want_retained;

		rc = mosquitto_subscribe_callback(
			on_message_simple, &userdata,
			topic, qos,
			host, port,
			client_id, keepalive, clean_session,
			username, password,
			will, tls);

		if (!rc && userdata.max_msg_count == 0) {
			*messages = userdata.messages;
			return MOSQ_ERR_SUCCESS;
		}
		else {
			for (i = 0; i < msg_count; i++) {
				mosquitto_message_free_contents(&userdata.messages[i]);
			}
			free(userdata.messages);
			userdata.messages = NULL;
			return rc;
		}
	}

	static void on_connect(struct mosquitto *mosq, void *obj, int rc)
	{
		struct userdata__callback *userdata = (userdata__callback*)obj;

		//UNUSED(rc); 

		mosquitto_subscribe(mosq, NULL, userdata->topic, userdata->qos);
	}

	static void on_message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
	{
		int rc;
		struct userdata__callback *userdata = (userdata__callback*)obj; // powinno dzialac

		rc = userdata->callback(mosq, userdata->userdata, message);
		if (rc) {
			mosquitto_disconnect(mosq);
		}
	}

	static int on_message_simple(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message)
	{
		struct userdata__simple *userdata = (userdata__simple*)obj; // powinno dzialac
		int rc;

		if (userdata->max_msg_count == 0) {
			return 0;
		}

		/* Don't process stale retained messages if 'want_retained' was false */
		if (!userdata->want_retained && message->retain) {
			return 0;
		}

		userdata->max_msg_count--;

		rc = mosquitto_message_copy(&userdata->messages[userdata->message_count], message);
		if (rc) {
			return rc;
		}
		userdata->message_count++;
		if (userdata->max_msg_count == 0) {
			mosquitto_disconnect(mosq);
		}
		return 0;
	}

	struct mosquitto* mosquitto_new(const char *id, bool clean_session, void *obj)
	{
		return new mosquitto();
	}

	int mosquitto_will_set(struct mosquitto *mosq, const char *topic, int payloadlen, const void *payload, int qos, bool retain)
	{
		return -1;
	}

	void mosquitto_destroy(struct mosquitto *mosq)
	{

	}

	int mosquitto_username_pw_set(struct mosquitto *mosq, const char *username, const char *password)
	{
		return -1;
	}


	int mosquitto_tls_set(struct mosquitto *mosq,
		const char *cafile, const char *capath,
		const char *certfile, const char *keyfile,
		int(*pw_callback)(char *buf, int size, int rwflag, void *userdata))
	{
		return -1;
	}

	int mosquitto_tls_opts_set(struct mosquitto *mosq, int cert_reqs, const char *tls_version, const char *ciphers)
	{
		return -1;
	}

	void mosquitto_connect_callback_set(struct mosquitto *mosq, void(*on_connect)(struct mosquitto *, void *, int))
	{

	}

	void mosquitto_message_callback_set(struct mosquitto *mosq, void(*on_message)(struct mosquitto *, void *, const struct mosquitto_message *))
	{

	}



	int mosquitto_connect(struct mosquitto *mosq, const char *host, int port, int keepalive)
	{
		return -1;
	}

	int mosquitto_loop_forever(struct mosquitto *mosq, int timeout, int max_packets)
	{
		return -1;
	}


	void mosquitto_message_free_contents(struct mosquitto_message *message)
	{

	}

	int mosquitto_subscribe(struct mosquitto *mosq, int *mid, const char *sub, int qos)
	{
		return -1;
	}

	int mosquitto_disconnect(struct mosquitto *mosq)
	{
		return -1;
	}

	int mosquitto_message_copy(struct mosquitto_message *dst, const struct mosquitto_message *src)
	{
		return -1;
	}

}