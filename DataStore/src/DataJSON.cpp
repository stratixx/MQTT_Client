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
#include <cstring>
#include <cstdlib>

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

void DataJSON::writeJSONToFile(string fileName, MQTT_Data_t &messageFromBroker)
{
	string writingPath;
	string currentPath = this->getCurrentWorkingDirectory();
	std::size_t pos = currentPath.find("build");
	currentPath = currentPath.substr(0, pos);
	string directoryDatabase = string("Database");
	currentPath += directoryDatabase;
	cout << currentPath;

	string goOtrzymuje = "/merakimv/Q2HV-6YJL-JGJ4/raw_detections"; //topic
	std::string s = messageFromBroker.topic;
	std::replace(s.begin(), s.end(), '/', '\\'); 
	cout << endl;
	
	while (!s.empty())
	{
		//string sOrginal = s;
		string temp = getStringForPath(s);

		cout << "Z ucinania" << temp << endl;
		writingPath = currentPath + temp;
		cout << "Writing: " << writingPath << endl;

		int check;
		const char *c = writingPath.c_str();
		check = mkdir(c);
		if (!check) {
			printf("Directory created\n");
			currentPath = currentPath + temp;
		}
		else {
			printf("Unable to create directory\n");
			currentPath = currentPath + temp;
			return ;
		}

		std::size_t pos = s.find(temp);
		s = s.substr(pos+temp.length());
		cout << "AFTER SUBSTR" << s<<endl;
	}
}

string DataJSON::getStringForPath(string s)
{
	std::size_t a;
	std::size_t b;
	string temp;
	a = s.find("\\");
	if (a != std::string::npos)
		cout << "A:: " << a << endl;
	b = s.find("\\", a + 1);
	if (b != std::string::npos) {
		cout << "B:: " << b << endl;
		temp = s.substr(a, b);
	}
	else {
		temp = s.substr(a);
	}
	return temp;
}

void DataJSON::replaceFunction() {
	std::string s = "example string";
	std::replace(s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
}