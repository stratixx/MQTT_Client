/*
*
*
*
*/
#include "../include/Subscriber.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

#include <DataStore.hpp>
#include <DataJSON.hpp>

using namespace std;
using namespace DataStore_NS;
using namespace MQTT_Client_NS;


/*! \file Subscriber.cpp
	\brief Implementation of subscriber function. 
*/

////////////////////////////////////////////////////////////////
int main()
{
	SubscriberCallbacks callbacks;
	DataStore dataStore;
	MQTT_Client client(MQTTBrokerAddress, ClientID);
	int ch;

	std::cout << "Hello World!: Subscriber\n";

	DataJSON *dataJSON = new DataJSON();
	
	//client.setAddress(MQTTBrokerAddress);
	//client.setClientID(ClientID);
	client.connect();
	client.setCallback(&callbacks);

	client.subscribe(TopicSubscribeName);

	do
	{
		ch = getchar();
	} while (ch != 'Q' && ch != 'q');

	client.unsubscribe(TopicSubscribeName);
	client.disconnect();

}

/**********************************************************************************************//**
 * \fn	void SubscriberCallbacks::callbackMessageArrived(MQTT_Data_t& data)
 *
 * \brief	Callback message arrived
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	data	The data.
 **************************************************************************************************/

void SubscriberCallbacks::callbackMessageArrived(MQTT_Data_t& data)
{
	cout << "Message arrived: " << endl;
	cout << "      topic: " << data.topic << endl;
	cout << "    message: ";
	std::copy(data.dataVector.begin(), data.dataVector.end(),
		std::ostream_iterator<char>(std::cout, ""));
	cout << endl;

	DataJSON *dataJSON = new DataJSON();
	dataJSON->writeJSONToFile("writingExampleJSON2.json", data);	
}

/**********************************************************************************************//**
 * \fn	void SubscriberCallbacks::callbackConnectionLost(std::string& cause)
 *
 * \brief	Callback connection lost
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	cause	The cause.
 **************************************************************************************************/

void SubscriberCallbacks::callbackConnectionLost(std::string& cause)
{
	cout << "Connection lost!" << endl;
}
