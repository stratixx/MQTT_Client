/*
*
*
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
        //typedef std::shared_ptr<MQTT_Client*>   PMQTT_Client;
        //typedef std::weak_ptr<MQTT_Client*>     PWMQTT_Client;

    public:
      Connection* connection;

      bool setConnectionType(std::string);

	  MQTT_Client();
	  ~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
    };
}

#endif