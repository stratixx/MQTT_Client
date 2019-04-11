/*
*
*
*
*/
#include <iostream>
#include <MQTT_Client.hpp>
#include <DataStore.hpp>
//#include <boost/smart_ptr.hpp>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;

int main()
{
    std::cout << "Hello World!: Subscriber\n";

	MQTT_Client client;
	DataStore dataStore;


	cout << "5+6=" << client.add(5, 6) << endl;
	cout << "5+6=" << dataStore.add(5, 6) << endl;

}
