// MQTT_Client.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
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