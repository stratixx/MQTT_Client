﻿/*
*
*
*
*/
#include "../include/Subscriber.hpp"
#include <iostream>

#include <MQTT_Client.hpp>
#include <DataStore.hpp>
#include <DataJSON.hpp>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;

DataStore dataStore;
MQTT_Client client;

int main()
{
	std::cout << "Hello World!: Subscriber\n";
	DataJSON *dataJSON = new DataJSON();
	dataJSON->readJSONFromFile("exampleJSON2.json");
	client.setPort(1883);
	client.setAddress("test.mosquitto.org");
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
	string localData;

	cout<<"callbackFun: topic: "<<data.topic<<"; data: "<<data.data<<"; "<<endl;

	localData = data.data;

	dataStore.writeData(localData);

	return false;
}
