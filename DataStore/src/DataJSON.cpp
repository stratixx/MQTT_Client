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
#include <algorithm>
#include <string>

#include <stdio.h>  /* defines FILENAME_MAX */
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>

//#include <boost/filesystem.hpp>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std; 

DataJSON::DataJSON() {}

DataJSON::~DataJSON() {}

string DataJSON::getCurrentWorkingDirectory()
{
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	std::cout << current_working_dir << std::endl;
	return current_working_dir;
}

ifstream DataJSON::loadJsonFile(string fileName)
{
	string beginOfString = string("./");
	fileName = beginOfString + fileName;
	std::ifstream data_file(fileName, std::ifstream::in);

	if (data_file.good() == true)
		cout << "I have acces to file" << endl;
	else
		cout << "I don't have acces to file" << endl;
	
	return data_file;
}

string DataJSON::readJSONFromFile(string fileName)
{
	string lineToReturn;
	try {
		boost::property_tree::ptree jsontree;
		
		ifstream data_file = loadJsonFile(fileName);

		boost::property_tree::write_xml("file2.xml", jsontree);
		ifstream in("file2.xml");

		bool begin_tag = false;
		while (getline(in, lineToReturn))
		{
			std::string tmp; // strip whitespaces from the beginning
			for (int i = 0; i < lineToReturn.length(); i++)
			{
				if (lineToReturn[i] == ' ' && tmp.size() == 0)
				{
				}
				else
				{
					tmp += lineToReturn[i];
				}
			}
		}
		
		cout << "line: " << lineToReturn << endl;

		data_file.close();
	}
	catch (boost::property_tree::json_parser::json_parser_error) {
		cout << "Error by reading a file" << endl;
		return "0";
	}

	cout << "The file was load" << endl;
	return lineToReturn;
}

void DataJSON::writeJSONToFile(string fileName, MQTT_Data_t messageFromBroker)
{
	string currentPath = this->getCurrentWorkingDirectory();
	std::size_t pos = currentPath.find("build");
	currentPath = currentPath.substr(0, pos);
	string directoryDatabase = string("Database");
	currentPath += directoryDatabase;
	cout << currentPath;

	// tu zmienic na zmienna topic z MQTT Data 
	string goOtrzymuje = "/merakimv/Q2HV-6YJL-JGJ4/raw_detections"; //topic
	std::string s = "/merakimv/Q2HV-6YJL-JGJ4/raw_detections";
	std::replace(s.begin(), s.end(), '/', '\\'); // replace all 'x' to 'y'
	cout << endl;
	s = currentPath + s;
	cout << "CCCCCCCCCCCCC: " << s << endl;
	int check;
	const char *c = s.c_str();
	check = mkdir(c);
	if (!check)
		printf("Directory created\n");
	else {
		printf("Unable to create directory\n");
		return ;
	}
	//boost::filesystem::create_directory(s);
	/*int check;
	int length = s.length();
	char arrayMkdir[length + 1];
	strcpy(arrayM)
	check = mkdir((char)s);*/

	/*
	Json::Value root;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "\t";
	std::string document = Json::writeString(wbuilder, root);
	std::ofstream output_file(fileName);
	output_file << document;
	output_file.close();
	*/
}

void replaceFunction() {
	std::string s = "example string";
	std::replace(s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
}