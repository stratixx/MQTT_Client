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

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void mythread()
{
	std::cout << '{' << '\n';
	for (int i = 0; i < 5; ++i)
	{
		wait(1);
		std::cout << i << '\n';
	}
	
	std::cout << '}' << '\n';
}

namespace MQTT_Client_NS
{

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

	MQTT_Client::MQTT_Client()
	{
		connection = (Connection*)nullptr;
	}

	MQTT_Client::~MQTT_Client()
	{
		if (connection != nullptr)
			delete connection;
	}

}