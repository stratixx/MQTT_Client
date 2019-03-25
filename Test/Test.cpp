// Test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#define BOOST_TEST_MODULE MyTest
//#include <boost/test/unit_test.hpp>

#include <iostream>
#include <boost/any.hpp>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "../MQTT_Client/MQTT_Client.h"

using namespace std;

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void thread()
{
	for (int i = 0; i < 5; ++i)
	{
		wait(1);
		std::cout << i << '\n';
	}
}

/*
BOOST_AUTO_TEST_CASE( my_test )
{
    MQTT_Client client;
    
    BOOST_CHECK( client.add( 2,2 ) == 4 );        // #1 continues on error

}
*/

using namespace MQTT_Client_NS;
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
    MQTT_Client client;

    //cout<<"ClientState: "<<client.getState()<<endl;
    if( client.add(5,6)==11 )
        return 0;
    else
        return -1;

	//boost::thread t{ thread };
	//t.join();

    return 0;
}

