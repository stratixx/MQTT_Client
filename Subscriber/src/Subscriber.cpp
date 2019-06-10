/*
*
*
*
*/
#include "../include/Subscriber.hpp"
#include <iostream>

#include <DataStore.hpp>
#include <DataJSON.hpp>

using namespace DataStore_NS;
using namespace MQTT_Client_NS;



////////////////////////////////////////////////////////////////
int main()
{
	SubscriberCallbacks callbacks;
	DataStore dataStore;
	MQTT_Client client;

	std::cout << "Hello World!: Subscriber\n";

	DataJSON *dataJSON = new DataJSON();
	MQTT_Data_t exampleData;
	dataJSON->writeJSONToFile("exampleJSON2.json", exampleData);

	client.setAddress(MQTTBrokerAddress);
	client.setClientID(ClientID);
	client.connect();
	client.setCallback(&callbacks);

	client.subscribe(TopicSubscribeName);

	client.spinOnce();
	client.spinOnce();
	client.spinOnce();

	client.unsubscribe(TopicSubscribeName);
	client.disconnect();

}

void SubscriberCallbacks::callbackDelivered(MQTTCallback::MQTTClientContext_t context, MQTTClient_deliveryToken token)
{

}

void SubscriberCallbacks::callbackMesageArrived(MQTTCallback::MQTTClientContext_t context, MQTT_Data_t& data)
{

}

void SubscriberCallbacks::callbackConnectionLost(MQTTCallback::MQTTClientContext_t context, std::string& cause)
{

}
