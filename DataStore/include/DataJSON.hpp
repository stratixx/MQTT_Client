/*
*
*
*
*/
#ifndef DATAJSON_H
#define DATAJSON_H

#include <string>
#include "../include/DataArchive.hpp"
#include "../src/json/json.h" //this file add library for json serialization 

using namespace std;

class DataJSON:public DataArchive
{
public:
	DataJSON();
	~DataJSON();
	void writeJSONToFile(string fileName, MQTTdata data);
	void readJSONFromFile(string fileName);
};

#endif