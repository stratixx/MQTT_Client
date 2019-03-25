<<<<<<< HEAD:MQTT_Client/MQTT_Package/MQTT_Client.cpp
﻿// MQTT_Client.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <boost/any.hpp>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "MQTT_Client.hpp"
//#include "test.cpp"

MQTT_Client::MQTT_Client()
{
	state = false;
}


void MQTT_Client::setState(bool newState)
{
	state = newState;
}

bool MQTT_Client::getState()
{
    return state;
}

int MQTT_Client::add(int a,int b)
{
    return a+b;
}

int MQTT_Client::mul(int a,int b)
{
    return a*b;
}


/*void main()
{
	std::cout << "Hello Konrad :D dziala :D ";
}*/
=======
#include "MQTT_Client.h"

namespace MQTT_Client_NS
{

	int MQTT_Client::add(int a, int b)
	{
		return a + b;
	}

	int MQTT_Client::mul(int a, int b)
	{
		return a * b;
	}

}
>>>>>>> 0be6dbc4efecbed5c496d5a798af3ffc2cfc39ea:MQTT_Client/MQTT_Client.cpp
