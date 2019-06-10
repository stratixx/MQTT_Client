
#include <iostream>
#include "../include/MQTT_Client.hpp"
#define BOOST_TEST_MODULE TestUnencryptedBis
#include <boost/test/unit_test.hpp>


/*! \file setConnectionType_unencryptedBis.cpp
	\brief File with tests for unecncypted connection
*/

BOOST_AUTO_TEST_CASE( test_unencrypted_bis )
{
    using namespace MQTT_Client_NS;

    cout<<"Test2 test encrypted"<<endl;
    MQTT_Client client;

    BOOST_CHECK(client.setConnectionType("unencrypted"));
}


// int main()
// {
//     return -1;
// }