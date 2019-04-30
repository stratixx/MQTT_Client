
#include <iostream>
#include "../include/MQTT_Client.hpp"
#define BOOST_TEST_MODULE Test_MQTT_Client
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test_unencrypted )
{
    using namespace MQTT_Client_NS;
    using namespace std;

    cout<<"Test1 test unencrypted"<<endl;
    MQTT_Client client;

    BOOST_CHECK(client.setConnectionType("unencrypted"));
    BOOST_CHECK(client.setConnectionType("encrypted"));
    
}

BOOST_AUTO_TEST_CASE( test_encrypted )
{
    using namespace MQTT_Client_NS;

    cout<<"Test1 test encrypted"<<endl;
    MQTT_Client client;

    BOOST_CHECK(client.setConnectionType("unencrypted"));
}

