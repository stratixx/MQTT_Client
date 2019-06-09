/*
*
*
*
*/
#ifndef DATAJSON_H
#define DATAJSON_H

#include <string>
//#include "../include/DataArchive.hpp"
#include "../src/json/json.h" //this file add library for json serialization 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>


using namespace std;

class DataJSON 
{
public:
	DataJSON();
	~DataJSON();
	//void writeJSONToFile(string fileName, MQTTdata data);
	void readJSONFromFile(string fileName);
	string getCurrentWorkingDirectory();
	ifstream loadJsonFile(string fileName);
};

#endif