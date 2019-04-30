/*
*
*
*
*/
#ifndef DATAARCHIVE_H
#define DATAARCHIVE_H

#include <string>

using namespace std;

class DataArchive {
	string typeOfData = NULL;

public:
	DataArchive();
	DataArchive(string dataType);
	~DataArchive();
};

#endif
