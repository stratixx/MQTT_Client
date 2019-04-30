/*
*
*
*
*/
#include "../include/DataArchive.hpp"
#include <iostream>

DataArchive::DataArchive() {}

DataArchive::DataArchive(string dataType)
{
	this->typeOfData = dataType;
}

DataArchive::~DataArchive() {}