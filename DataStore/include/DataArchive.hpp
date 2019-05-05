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
	void writeJSONToFile(string fileName, MQTTdata data);
	void readJSONFromFile(string fileName);
	bool writeToSQLBase(string fileName);
	bool readFromSQLBase(string fileName);
};

#endif
