/*!
* \file MQTTCallback.cpp
* \brief Class for mechanism callback in MQTT Protocol
*/

#ifndef MQTT_Callback_H 
#define MQTT_Callback_H

#include <boost/smart_ptr.hpp>
#include <string>
#include "../../paho.mqtt.c/src/MQTTClient.h"

#include "MQTTData.hpp"

using namespace std;
using namespace boost;

/**********************************************************************************************//**
 * \class	MQTTCallback
 *
 * \brief	A mqtt callback.
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

class MQTTCallback
{
public:


  //typedef std::shared_ptr<MQTTCallback>   MQTTCallbackPointer;

  /**********************************************************************************************//**
   * \typedef	MQTTClient_deliveryToken MQTTClientDeliveryToken_t
   *
   * \brief	Defines an alias representing the mqtt client delivery token t
   **************************************************************************************************/

  typedef MQTTClient_deliveryToken MQTTClientDeliveryToken_t;

  /**********************************************************************************************//**
   * \fn	virtual void callbackDelivered(MQTTClientDeliveryToken_t&)
   *
   * \brief	Callback delivered
   *
   * \author	Marcin Dolicher
   * \date	10.06.2019
   *
   * \param [in,out]	parameter1	The first parameter.
   **************************************************************************************************/

  virtual void callbackDelivered(MQTTClientDeliveryToken_t&) {  };

  /**********************************************************************************************//**
   * \fn	virtual void callbackMessageArrived(MQTT_Data_t&)
   *
   * \brief	Callback message arrived
   *
   * \author	Marcin Dolicher
   * \date	10.06.2019
   *
   * \param [in,out]	parameter1	The first parameter.
   **************************************************************************************************/

  virtual void callbackMessageArrived(MQTT_Data_t&) {  };

  /**********************************************************************************************//**
   * \fn	virtual void callbackConnectionLost(std::string&)=0;
   *
   * \brief	Callback connection lost
   *
   * \author	Marcin Dolicher
   * \date	10.06.2019
   *
   * \param [in,out]	parameter1	The first parameter.
   **************************************************************************************************/

  virtual void callbackConnectionLost(std::string&)=0;

private:

};

#endif
