/*
*
*
*
*/
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

/*! \file Subscriber.hpp
	\brief Implementation of subscriber function.
*/ 
#include <MQTT_Client.hpp>
#include <DataJSON.hpp>

// TO DO: wczytanie parametrów z pliku konfiguracyjnego
/** \brief	The mqtt broker address */
const string MQTTBrokerAddress("tcp://broker.hivemq.com:1883");
/** \brief	Identifier for the client */
const string ClientID("ZPR_MQTT_ClientSub");
/** \brief	Name of the topic subscribe */
const string TopicSubscribeName("/merakimv/Q2GV-6GUN-CL8A/light");
/** \brief	The mqtt qos */
const int MQTT_QOS = 1;
/** \brief	The timeout */
const int Timeout = 10000L;

/**********************************************************************************************//**
 * \class	SubscriberCallbacks
 *
 * \brief	A subscriber callbacks.
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

class SubscriberCallbacks : public MQTTCallback
{
public:

	DataJSON dataJSON;

	void callbackMessageArrived(MQTT_Data_t& data) override;

	void callbackConnectionLost(std::string& cause) override;

	SubscriberCallbacks();
};

#endif
