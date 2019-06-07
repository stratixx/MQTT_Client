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
	#ifdef _WIN32

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
		service.sin_addr.s_addr = inet_addr("127.0.0.1");
		service.sin_port = htons(27015);

		if (::connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
		{
			printf("Failed to connect.\n");
			WSACleanup();
			return false;
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