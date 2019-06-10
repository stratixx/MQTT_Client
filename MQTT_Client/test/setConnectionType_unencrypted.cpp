
#include <iostream>
#include "../include/MQTT_Client.hpp"
#define BOOST_TEST_MODULE TestUnencrypted
#include <boost/test/unit_test.hpp>

/*! \file setConnectionType_unencrypted.cpp
	\brief File with tests for unecncypted connection
*/

BOOST_AUTO_TEST_CASE( test_unencrypted )
{
    using namespace MQTT_Client_NS;
    using namespace std;

    cout<<"Test1 test unencrypted"<<endl;
    MQTT_Client client;

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }