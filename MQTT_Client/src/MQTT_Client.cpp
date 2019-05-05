/*
*
*
*
*/
#include "../include/MQTT_Client.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

#include "../include/ConnectionUnencrypted.h"


namespace MQTT_Client_NS
{

    bool MQTT_Client::spinOnce()
	{
		bool result;
		MQTT_Data_t data("MQTT spin once data");

		if(callback==nullptr)
			return false;

		result = (*callback)(data);

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
		return false;
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