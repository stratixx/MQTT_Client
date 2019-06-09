/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#include "../include/MQTT_Client.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>


#include "../include/ConnectionUnencrypted.h"

#pragma comment(lib,"WS2_32")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

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
	#ifdef _WIN32

		WSADATA wsaData;
		SOCKET ConnectSocket = INVALID_SOCKET;
		struct addrinfo *result = NULL,
			*ptr = NULL,
			hints;
		char *sendbuf = "MQTT"; // tu bylo MQTT
		char recvbuf[DEFAULT_BUFLEN];
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;

		// Validate the parameters
		/*if (argc != 2) {
			printf("usage: %s server-name\n", argv[0]);
			return 1;
		}*/

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
			return 1;
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		// Resolve the server address and port
		// iResult = getaddrinfo("test.mosquitto.org", "1883", &hints, &result);
		iResult = getaddrinfo("iot.eclipse.org", "80", &hints, &result);
		if (iResult != 0) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		// Attempt to connect to an address until one succeeds
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

			// Create a SOCKET for connecting to server
			ConnectSocket = ::socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ConnectSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
				return 1;
			}

			// Connect to server.
			iResult = ::connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}

		freeaddrinfo(result);

		if (ConnectSocket == INVALID_SOCKET) {
			printf("Unable to connect to server!\n");
			WSACleanup();
			return 1;
		}

		char id [5];
		id[0] = 'm';
		id[1] = 'q';
		id[2] = 't';
		id[3] = 't';
		id[4] = '/';
		// Send an initial buffer
		// (int)strlen(sendbuf)
		iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
		if (iResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}

		printf("Bytes Sent: %ld\n", iResult);

		// shutdown the connection since no more data will be sent
		iResult = shutdown(ConnectSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}

		// Receive until the peer closes the connection
		do {

			iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0)
				printf("Bytes received: %d\n", iResult);
			else if (iResult == 0)
				printf("Connection closed\n");
			else
				printf("recv failed with error: %d\n", WSAGetLastError());

		} while (iResult > 0);

		// cleanup
		closesocket(ConnectSocket);
		WSACleanup();

		/*
		TO CO ZROBILEM, ZOSTAWIAM TUTAJ
		WSADATA wsaData;

		int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != NO_ERROR)
		{
			printf("Initialization error.\n");
			return false;
		}

		SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (mainSocket == INVALID_SOCKET)
		{
			printf("Error creating socket: %ld\n", WSAGetLastError());
			WSACleanup();
			return false;
		}

		sockaddr_in service;
		memset(&service, 0, sizeof(service));
		service.sin_family = AF_INET;
		service.sin_addr.s_addr = inet_addr("test.mosquitto.org");
		service.sin_port = htons(8080);

		if (::connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
		{
			printf("Failed to connect.\n");
			WSACleanup();
			return false;
		}
		*/
	#else //_WIN32

	#endif // _WIN32


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

}