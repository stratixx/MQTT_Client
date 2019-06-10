/*
*
*
*
*/
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <MQTT_Client.hpp>

// TO DO: wczytanie parametrów z pliku konfiguracyjnego
const string MQTTBrokerAddress("tcp://broker.hivemq.com:1883");
const string ClientID("ZPR_MQTT_ClientPub");
const string TopicSubscribeName("/merakimv/Q2GV-6GUN-CL8A/light");
const int MQTT_QOS = 1;
const int Timeout = 10000L;


class SubscriberCallbacks : public MQTTCallback
{
public:
	void callbackMessageArrived(MQTT_Data_t& data) override;

	void callbackConnectionLost(std::string& cause) override;
};

#endif
