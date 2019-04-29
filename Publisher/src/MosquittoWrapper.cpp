#include <iostream>
#include "../include/MosquittoWrapper.hpp"
#include <MQTT_Client.hpp>
#include <DataStore.hpp>
#include <mosquittopp.h>

using namespace MQTT_Client_NS;
using namespace DataStore_NS;
using namespace std;

MosquittoWrapper::MosquittoWrapper(const char * _id, const char * _topic, const char * _host, int _port) : mosquittopp(_id)
{
	mosqpp::lib_init();        // Mandatory initialization for mosquitto library
	this->keepalive = 60;    // Basic configuration setup for MosquittoWrapper class
	this->id = _id;
	this->port = _port;
	this->host = _host;
	this->topic = _topic;
	connect_async(host, port, keeplive);    // non blocking connection to broker request
	loop_start();            // Start thread managing connection / publish / subscribe
};

MosquittoWrapper::~MosquittoWrapper() {
	loop_stop();            // Kill the thread
	mosqpp::lib_cleanup();    // Mosquitto library cleanup
}

bool MosquittoWrapper::send_message(const  char * _message)
{
	// Send message - depending on QoS, mosquitto lib managed re-submission this the thread
	//
	// * NULL : Message Id (int *) this allow to latter get status of each message
	// * topic : topic to be used
	// * lenght of the message
	// * message
	// * qos (0,1,2)
	// * retain (boolean) - indicates if message is retained on broker or not
	// Should return MOSQ_ERR_SUCCESS
	int ret = publish(NULL, this->topic, strlen(_message), _message, 1, false);
	return (ret == MOSQ_ERR_SUCCESS);
}

void MosquittoWrapper::on_disconnect(int rc) {
	std::cout << ">> MosquittoWrapper - disconnection(" << rc << ")" << std::endl;
}

void MosquittoWrapper::on_connect(int rc)
{
	if (rc == 0) {
		std::cout << ">> MosquittoWrapper - connected with server" << std::endl;
	}
	else {
		std::cout << ">> MosquittoWrapper - Impossible to connect with server(" << rc << ")" << std::endl;
	}
}

void MosquittoWrapper::on_publish(int mid)
{
	std::cout << ">> MosquittoWrapper - Message (" << mid << ") succeed to be published " << std::endl;
}

int main()
{
	MosquittoWrapper * pointerMosquittoWrapper;
	pointerMosquittoWrapper = new MosquittoWrapper();

}