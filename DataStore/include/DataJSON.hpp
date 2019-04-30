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
private:
	bool write();
	bool read();
};

#endif