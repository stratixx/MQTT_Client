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


int main()
{
    std::cout << "Hello World!: Publisher\n";

	MQTT_Client client;
	DataStore dataStore;


	cout << "set connection type unencrypted" << client.setConnectionType("unencrypted") << endl;
	cout << "set connection type encrypted" << client.setConnectionType("encrypted") << endl;
	cout << "5+6=" << dataStore.add(5, 6) << endl;

}
