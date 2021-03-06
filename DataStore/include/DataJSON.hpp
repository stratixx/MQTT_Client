/*
*
*
*
*/
/*! \file DataJSON.hpp
	\brief A header file of DataJSON class.
*/
#ifndef DATAJSON_H
#define DATAJSON_H

#include <string>
#include "../../MQTT_Client/include/MQTTData.hpp"
#include "../src/json/json.h" //this file add library for json serialization 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>

#ifdef _WIN32	
    #define filePathSeparator '\\'
#elif __linux__
	#define filePathSeparator '/'
#else
	#error("Unsuportted OS")
#endif

using namespace std;

/**********************************************************************************************//**
 * \class	DataJSON
 *
 * \brief	A data json.
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

class DataJSON 
{
public:

	DataJSON();
	~DataJSON();
	void writeJSONToFile(string fileName, MQTT_Data_t &messageFromBroker);
	string readJSONFromFile(string fileName);
	string getCurrentWorkingDirectory();
	ifstream loadJsonFile(string fileName);
	void replaceFunction();
	string getStringForPath(string stringIn);
};

#endif