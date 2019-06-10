/*
*
*
*
*/
#include <iostream>
#include "../include/Publisher.hpp"
#include <MQTT_Client.hpp>
#include <MQTTData.hpp>
#include <DataStore.hpp>
#include <DataJSON.hpp>
//#include <boost/smart_ptr.hpp>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;


int main()
{
	PublisherCallbacks callbacks;
	MQTT_Client client(MQTTBrokerAddress, ClientID);
	DataStore dataStore;

    std::cout << "Hello World!: Publisher\n";

	DataJSON *dataJSON = new DataJSON();
	dataJSON->readJSONFromFile("exampleJSON2.json");

	MQTT_Data_t data;
	string localData;

	//client.setAddress(MQTTBrokerAddress);
	//client.setClientID(ClientID);
	client.setCallback(&callbacks);
	client.connect();

	data.topic = TopicSubscribeName;
	data.dataType = MQTT_Data_t::data_t::STRING;

	while( (localData=dataStore.readData()).length() > 0 )
	{
		data.data = localData;
		client.publish(TopicSubscribeName, data);
	}

	client.publish(TopicSubscribeName, data);
	client.publish(TopicSubscribeName, data);
	client.publish(TopicSubscribeName, data);

	client.disconnect();
}

void PublisherCallbacks::callbackDelivered(MQTTClientDeliveryToken_t& token)
{

}

void PublisherCallbacks::callbackConnectionLost(std::string& cause)
{

}