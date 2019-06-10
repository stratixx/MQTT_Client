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

  virtual void callbackDelivered(MQTTClientDeliveryToken_t&) {  };
  virtual void callbackMessageArrived(MQTT_Data_t&) {  };
  virtual void callbackConnectionLost(std::string&)=0;

private:

};

#endif
