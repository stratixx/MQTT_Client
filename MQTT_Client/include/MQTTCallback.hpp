/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca mechanizm callbacków klasy MQTT_Client
*
*/

#ifndef MQTT_Callback_H 
#define MQTT_Callback_H

#include <boost/smart_ptr.hpp>
#include <string>
#include "../../paho.mqtt.c/src/MQTTClient.h"

#include "MQTTData.hpp"

using namespace std;
using namespace boost;

class MQTTCallback
{
public:


  //typedef std::shared_ptr<MQTTCallback>   MQTTCallbackPointer;
  typedef MQTTClient_deliveryToken MQTTClientDeliveryToken_t;
  typedef void* MQTTClientContext_t;

  virtual void callbackDelivered(MQTTClientContext_t, MQTTClient_deliveryToken)=0;
  virtual void callbackMesageArrived(MQTTClientContext_t, MQTT_Data_t&)=0;
  virtual void callbackConnectionLost(MQTTClientContext_t, std::string&)=0;

private:

};

#endif
