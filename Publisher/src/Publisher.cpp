/*
*
*
*
*/
#include <iostream>
#include "../include/Publisher.hpp"
#include <MQTT_Client.hpp>
#include <DataStore.hpp>
//#include <boost/smart_ptr.hpp>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;

MQTT_Client client;
DataStore dataStore;

int main()
{
    std::cout << "Hello World!: Publisher\n";

	MQTT_Client::MQTT_Data_t data;
	string localData;
	string topic("testTopic_2137");

	client.setPort(1883);
	client.setAddress("https://test.mosquitto.org/");
	client.connect();

	data.topic = topic;
	data.dataType = MQTT_Client::MQTT_Data_t::data_t::TEXT;

	while( (localData=dataStore.readData()).length() > 0 )
	{
		data.data = localData;
		client.publish(topic, data);
	}

	client.publish(topic, data);
	client.publish(topic, data);
	client.publish(topic, data);

	client.disconnect();
}
