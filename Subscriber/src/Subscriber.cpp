/*
*
*
*
*/
#include "../include/Subscriber.hpp"
#include <iostream>

#include <MQTT_Client.hpp>
#include <DataStore.hpp>
#include <DataJSON.hpp>
//#include <boost/smart_ptr.hpp>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;


DataStore dataStore;

int main()
{
	std::cout << "Hello World!: Subscriber\n";

	MQTT_Client client;

	client.setPort(1883);
	client.setAddress("https://test.mosquitto.org/");
	client.connect();
	client.setCallback(callbackFun);

	client.subscribe("#");

	client.spinOnce();
	client.spinOnce();
	client.spinOnce();

	client.unsubscribe("#");
	client.disconnect();
}

bool callbackFun(MQTT_Client::MQTT_Data_t& data )
{
	cout<<"callbackFun: "<<data<<endl;
	dataStore.writeData();

	return false;
}