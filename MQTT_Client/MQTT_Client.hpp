/*
*
*
*
*/
#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

//#include <boost/smart_ptr.hpp>

namespace MQTT_Client_NS
{
    class MQTT_Client;

    class MQTT_Client
    {
        //typedef shared_ptr<MQTT_Client>   PMQTT_Client;
        //typedef weak_ptr<MQTT_Client>     PWMQTT_Client;

    public:
        int add(int, int);
		int mul(int, int);

    private:
        //PMQTT_Client mqtt_ClientPtr_;
    };
}

#endif