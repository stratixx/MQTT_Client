/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <boost/smart_ptr.hpp>
#include <string>
#include "Connection.h"

namespace MQTT_Client_NS
{
	using namespace std;
	using namespace boost;

    class MQTT_Client;

    class MQTT_Client
    {
    public:
      //typedef std::shared_ptr<MQTT_Client*>   PMQTT_Client;
      //typedef std::weak_ptr<MQTT_Client*>     PWMQTT_Client;
      typedef struct
      {
        typedef enum
        {
          NONE,
          TEXT, 

        }data_t;

        string data;
        data_t dataType;
        string topic;
      }MQTT_Data_t;

      typedef bool (*callback_t)(MQTT_Data_t&);
      typedef int port_t;
      typedef std::string address_t;
      typedef std::string topicName_t;

      Connection* connection;
      callback_t callback;
      port_t port;
      address_t address;

      bool spinOnce();
      bool spin();

      bool setConnectionType(std::string);
      void setCallback(callback_t);
      void setPort(port_t);
      void setAddress(std::string&);
      void setAddress(const char*);

      bool connect();
      void disconnect();

      bool subscribe(std::string&);
      bool subscribe(const char*);

      bool unsubscribe(std::string&);
      bool unsubscribe(const char*);

      bool publish(std::string&, MQTT_Data_t&);
      bool publish(const char*, MQTT_Data_t&);


      MQTT_Client();
      ~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
    };
}

#endif