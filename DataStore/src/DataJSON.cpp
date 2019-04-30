/*
*
*
*
*/
#include "../include/DataJSON.hpp"
#include <iostream>
#include <fstream>
#include "json/json.h" //this file add library for json serialization 

using namespace std; 

DataJSON::DataJSON() {}

DataJSON::~DataJSON() {}

void DataJSON::readJSONFromFile(string fileName)
{
	Json::Value jsonFile;
	std::ifstream input_file(fileName, std::ifstream::binary);
	input_file >> jsonFile;

	cout << jsonFile; //This will print the entire json object.
}

void DataJSON::writeJSONToFile(string fileName, MQTTdata data)
{
	Json::Value root;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "\t";
	std::string document = Json::writeString(wbuilder, root);
	std::ofstream output_file(fileName);
	output_file << document;
	output_file.close();
}
