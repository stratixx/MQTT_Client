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
			data.dataType =  MQTT_Data_t::data_t::STRING;

			/*if(callback==nullptr)
				return false;*/


			MQTTCallback::MQTTClientContext_t context = nullptr;


			callback->callbackMesageArrived(context, data);
			result = true;
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

	bool MQTT_Client::setConnectionType(const std::string& type)
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

	void MQTT_Client::setCallback(MQTTCallback* callback_ )
	{
		callback = callback_;
	}

	void MQTT_Client::setPort(const port_t& port_)
	{
		port = port_;
	}

	void MQTT_Client::setAddress(const address_t& address_)
	{
		address = address_;
	}

	void MQTT_Client::setAddress(const char* address_)
	{
		address = address_t(address_);
	}

	void MQTT_Client::setClientID(const clientID_t& clientID_)
	{
		clientID = clientID_;
	}

	void MQTT_Client::setClientID(const char* clientID_)
	{
		setClientID(clientID_t(clientID_));
	}


	bool MQTT_Client::connect()
	{

		return true;
	}

	void MQTT_Client::disconnect()
	{

	}

	
	bool MQTT_Client::subscribe(const std::string& topic)
	{
/*
		MQTTClient client;
		MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
		int rc;
		int ch;

		MQTTClient_create(&client, ADDRESS, CLIENTID,
			MQTTCLIENT_PERSISTENCE_NONE, NULL);
		conn_opts.keepAliveInterval = 20;
		conn_opts.cleansession = 1;

		MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

		if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
		{
			printf("Failed to connect, return code %d\n", rc);
			exit(EXIT_FAILURE);
		}
		printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
			"Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
		MQTTClient_subscribe(client, TOPIC, QOS);

		do
		{
			ch = getchar();
		} while (ch != 'Q' && ch != 'q');

		MQTTClient_unsubscribe(client, TOPIC);
		MQTTClient_disconnect(client, 10000);
		MQTTClient_destroy(&client);
		return rc==0;*/
		return false;
	}

	bool MQTT_Client::subscribe(const char* topic_)
	{
		std::string topic(topic_);
		return subscribe(topic);
	}

	bool MQTT_Client::unsubscribe(const std::string& topic_)
	{
		return false;
	}

	bool MQTT_Client::unsubscribe(const char* topic_)
	{
		std::string topic(topic_);
		return unsubscribe(topic);
	}

	bool MQTT_Client::publish(const std::string& topic_, const MQTT_Data_t& data)
	{

		return false;
	}

	bool MQTT_Client::publish(const char* topic_, const MQTT_Data_t& data)
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