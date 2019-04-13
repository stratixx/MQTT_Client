/*
*
*
*
*/
#include "../include/MQTT_Client.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void mythread()
{
	for (int i = 0; i < 5; ++i)
	{
		wait(1);
		std::cout << i << '\n';
	}
}

namespace MQTT_Client_NS
{

	int MQTT_Client::add(int a, int b)
		{
		boost::thread t{ mythread };
		t.join();
		return a + b;
	}

	int MQTT_Client::mul(int a, int b)
	{
		return a * b;
	}

}