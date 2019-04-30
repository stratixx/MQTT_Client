/*
*
*
*
*/
#ifndef DATAARCHIVE_H
#define DATAARCHIVE_H

#include <string>

using namespace std;

typedef std::string MQTTdata;

class DataArchive {
	string typeOfData = NULL;

public:
	DataArchive();
	DataArchive(string dataType);
	~DataArchive();
private:
	virtual void writeJSONToFile(string fileName, MQTTdata data);
	virtual void readJSONFromFile(string fileName);
	virtual bool writeToSQLBase(string fileName);
	virtual bool readFromSQLBase(string fileName);
};

#endif
