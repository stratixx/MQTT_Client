/*
*
*
*
*/
#include "../include/DataJSON.hpp"
#include <iostream>
#include <fstream>
#include "json/json.h" //this file add library for json serialization 
#include <iostream>

using namespace std; 

DataJSON::DataJSON() {}

DataJSON::~DataJSON() {}

void DataJSON::readJSONFromFile(string fileName)
{
	boost::property_tree::ptree jsontree;
	boost::property_tree::read_json("fileName", jsontree);

	int v0 = jsontree.get<int>("a");
	int v1 = jsontree.get<int>("c");



	/*
	Json::Value jsonFile;
	std::ifstream input_file(fileName, std::ifstream::binary);
	input_file >> jsonFile;

	cout << jsonFile; //This will print the entire json object.
	*/
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
