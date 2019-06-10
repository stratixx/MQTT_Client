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



////////////////////////////////////////////////////////////////
int main()
{
	SubscriberCallbacks callbacks;
	DataStore dataStore;
	MQTT_Client client(MQTTBrokerAddress, ClientID);
	int ch;

	std::cout << "Hello World!: Subscriber\n";

<<<<<<< HEAD
	DataJSON *dataJSON = new DataJSON();
	MQTT_Data_t exampleData;
	dataJSON->writeJSONToFile("exampleJSON2.json", exampleData);

	client.setAddress(MQTTBrokerAddress);
	client.setClientID(ClientID);
=======



	//client.setAddress(MQTTBrokerAddress);
	//client.setClientID(ClientID);
>>>>>>> cbd2acf0fe4c888b5b6d613b6d415b91b6a3101f
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

void SubscriberCallbacks::callbackMessageArrived(MQTT_Data_t& data)
{
	cout << "Message arrived: " << endl;
	cout << "      topic: " << data.topic << endl;
	cout << "    message: ";
	std::copy(data.dataVector.begin(), data.dataVector.end(),
		std::ostream_iterator<char>(std::cout, ""));
	cout << endl;
	
}

void SubscriberCallbacks::callbackConnectionLost(std::string& cause)
{
	cout << "Connection lost!" << endl;
}
