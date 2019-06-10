/**
* @Author: Dolicher Marcin & Winnicki Konrad
* @brief Klasa implementująca protokół klienta MQTT
* @file MQTT_Client.cpp
*/

#include "../include/MQTT_Client.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>



#pragma comment(lib,"WS2_32")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"



namespace MQTT_Client_NS
{
	MQTT_Client::clients_t MQTT_Client::clients = MQTT_Client::clients_t();


	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setCallback(MQTTCallback* callback_ )
	 *
	 * \brief	Set the object callback
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param [in,out]	callback_	If non-null, the callback.
	 **************************************************************************************************/

	void MQTT_Client::setCallback(MQTTCallback* callback_ )
	{
		callback = callback_;
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setPort(const port_t& port_)
	 *
	 * \brief	Sets a port
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	port_	The port.
	 **************************************************************************************************/

	void MQTT_Client::setPort(const port_t& port_)
	{
		port = port_;
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setAddress(const address_t& address_)
	 *
	 * \brief	Sets the address
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	address_	The address.
	 **************************************************************************************************/

	void MQTT_Client::setAddress(const address_t& address_)
	{
		address = address_;
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setAddress(const char* address_)
	 *
	 * \brief	Sets the address
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	address_	The address.
	 **************************************************************************************************/

	void MQTT_Client::setAddress(const char* address_)
	{
		address = address_t(address_);
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setClientID(const clientID_t& clientID_)
	 *
	 * \brief	Sets client identifier
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	clientID_	Identifier for the client.
	 **************************************************************************************************/

	void MQTT_Client::setClientID(const clientID_t& clientID_)
	{
		clientID = clientID_;
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::setClientID(const char* clientID_)
	 *
	 * \brief	Sets client identifier
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	clientID_	Identifier for the client.
	 **************************************************************************************************/

	void MQTT_Client::setClientID(const char* clientID_)
	{
		setClientID(clientID_t(clientID_));
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::connect()
	 *
	 * \brief	Connects this object
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

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

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::disconnect()
	 *
	 * \brief	Disconnects this object
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 **************************************************************************************************/

	void MQTT_Client::disconnect()
	{
		MQTTClient_disconnect(libraryClient, 10000);
		MQTT_Client::clients.erase(context);
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::subscribe(const std::string& topic)
	 *
	 * \brief	Subscribes the given topic
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic	The topic.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::subscribe(const std::string& topic, const MQTT_QOS& qos)
	{
		MQTTClient_subscribe(libraryClient, topic.c_str(), qos);

		return true;
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::subscribe(const char* topic_)
	 *
	 * \brief	Subscribes the given topic
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic_	The topic.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::subscribe(const char* topic_, const MQTT_QOS& qos)
	{
		std::string topic(topic_);
		return subscribe(topic, qos);
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::unsubscribe(const std::string& topic)
	 *
	 * \brief	Unsubscribes the given topic
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic	The topic.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::unsubscribe(const std::string& topic)
	{
		 MQTTClient_unsubscribe(libraryClient, topic.c_str());

		return true;
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::unsubscribe(const char* topic_)
	 *
	 * \brief	Unsubscribes the given topic
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic_	The topic.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::unsubscribe(const char* topic_)
	{
		std::string topic(topic_);
		return unsubscribe(topic);
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::publish(const std::string& topic_, const MQTT_Data_t& data)
	 *
	 * \brief	Publishes
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic_	The topic.
	 * \param	data  	The data.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::publish(const std::string& topic_, const MQTT_Data_t& data)
	{

		return false;
	}

	/**********************************************************************************************//**
	 * \fn	bool MQTT_Client::publish(const char* topic_, const MQTT_Data_t& data)
	 *
	 * \brief	Publishes
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	topic_	The topic.
	 * \param	data  	The data.
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool MQTT_Client::publish(const char* topic_, const MQTT_Data_t& data)
	{
		std::string topic(topic_);
		return publish(topic, data);
	}

	/**********************************************************************************************//**
	 * \fn	MQTT_Client::MQTT_Client( const address_t& address_, const clientID_t& clientID_)
	 *
	 * \brief	Constructor
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param	address_ 	The address.
	 * \param	clientID_	Identifier for the client.
	 **************************************************************************************************/

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

	/**********************************************************************************************//**
	 * \fn	MQTT_Client::MQTT_Client()
	 *
	 * \brief	Default constructor
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 **************************************************************************************************/

	MQTT_Client::MQTT_Client()
	{
		callback = nullptr;
		port = 0;
		address = "";
	}

	/**********************************************************************************************//**
	 * \fn	MQTT_Client::~MQTT_Client()
	 *
	 * \brief	Destructor
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 **************************************************************************************************/

	MQTT_Client::~MQTT_Client()
	{
		MQTT_Client::clients.erase(context);
	}

	/**********************************************************************************************//**
	 * \fn	MQTT_Client::MQTTClientContext_t MQTT_Client::getNewContext()
	 *
	 * \brief	Gets a new context
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \returns	The new context.
	 **************************************************************************************************/

	MQTT_Client::MQTTClientContext_t MQTT_Client::getNewContext()
	{
		static MQTT_Client::MQTTClientContext_t context = 0;

		return ++context;
	}

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::delivered(void *context, MQTTClient_deliveryToken dt)
	 *
	 * \brief	Delivered
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param [in,out]	context	If non-null, the context.
	 * \param 		  	dt	   	The dt.
	 **************************************************************************************************/

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

	/**********************************************************************************************//**
	 * \fn	int MQTT_Client::msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
	 *
	 * \brief	Msgarrvds
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param [in,out]	context  	If non-null, the context.
	 * \param [in,out]	topicName	If non-null, name of the topic.
	 * \param 		  	topicLen 	Length of the topic.
	 * \param [in,out]	message  	If non-null, the message.
	 *
	 * \returns	An int.
	 **************************************************************************************************/

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

	/**********************************************************************************************//**
	 * \fn	void MQTT_Client::connlost(void *context, char *cause)
	 *
	 * \brief	Connlosts
	 *
	 * \author	Marcin Dolicher
	 * \date	10.06.2019
	 *
	 * \param [in,out]	context	If non-null, the context.
	 * \param [in,out]	cause  	If non-null, the cause.
	 **************************************************************************************************/

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