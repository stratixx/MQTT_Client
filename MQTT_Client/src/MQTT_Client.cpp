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
	MQTT_Client::clients_t MQTT_Client::clients = MQTT_Client::clients_t();


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



			callback->callbackMessageArrived(data);
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
		int rc;

		MQTTClient_setCallbacks(libraryClient, &context, connlost, msgarrvd, delivered);
		MQTT_Client::clients[context] = this;

		if ((rc = MQTTClient_connect(libraryClient, &connectOptions)) != MQTTCLIENT_SUCCESS)
		{
			printf("Failed to connect, return code %d\n", rc);
			MQTT_Client::clients.erase(context);
			return false;
		}

		return true;
	}

	void MQTT_Client::disconnect()
	{
		MQTTClient_disconnect(libraryClient, 10000);
		MQTT_Client::clients.erase(context);
	}

	
	bool MQTT_Client::subscribe(const std::string& topic)
	{
		MQTTClient_subscribe(libraryClient, topic.c_str(), 1);

		return true;
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

	MQTT_Client::MQTT_Client( const address_t& address_, const clientID_t& clientID_) : 
		address(address_), 
		clientID(clientID_)
	{
		MQTTClient_create(&libraryClient, address.c_str(), clientID.c_str(),
			MQTTCLIENT_PERSISTENCE_NONE, NULL);

		connectOptions = MQTTClient_connectOptions_initializer;
		connectOptions.keepAliveInterval = 20;
		connectOptions.cleansession = 1;

		context = getNewContext();
		MQTTClient_setCallbacks(libraryClient, &context, connlost, msgarrvd, delivered);

		MQTT_Client::clients[context] = this;
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

		MQTT_Client::clients.erase(context);
	}


	MQTT_Client::MQTTClientContext_t MQTT_Client::getNewContext()
	{
		static MQTT_Client::MQTTClientContext_t context = 0;

		return ++context;
	}

	void MQTT_Client::delivered(void *context, MQTTClient_deliveryToken dt)
	{
		MQTT_Client::MQTTClientContext_t context_ = *(MQTT_Client::MQTTClientContext_t*)context;

		MQTT_Client::clients_t::iterator iter =  MQTT_Client::clients.find(context_);

		if (iter == MQTT_Client::clients.end())
		{
			// not found
		}
		else
		{
			iter->second->callback->callbackDelivered(dt);
		}
	}

	int MQTT_Client::msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
	{
		MQTT_Client::MQTTClientContext_t context_ = *(MQTT_Client::MQTTClientContext_t*)context;

		clients_t::iterator iter = MQTT_Client::clients.find(context_);

		if (iter == MQTT_Client::clients.end())
		{
			// not found
			return -1;
		}
		else
		{
			MQTT_Data_t data;
			char * payloadPtr = (char*)message->payload;

			//data.dataType = MQTT_Data_t::data_t::STRING;
			//data.topic.assign(topicName, topicLen);
			data.topic = topicName;
			data.dataVector.reserve(message->payloadlen);
			data.dataVector.insert(data.dataVector.end(), &(payloadPtr[0]), &(payloadPtr[message->payloadlen]));

			iter->second->callback->callbackMessageArrived(data);
			return 0;
		}
	}

	void MQTT_Client::connlost(void *context, char *cause)
	{
		MQTT_Client::MQTTClientContext_t context_ = *(MQTT_Client::MQTTClientContext_t*)context;

		MQTT_Client::clients_t::iterator iter = MQTT_Client::clients.find(context_);

		if (iter == MQTT_Client::clients.end())
		{
			// not found
		}
		else
		{
			std::string causeStr = cause;
			iter->second->callback->callbackConnectionLost(causeStr);
		}
		
	}

}