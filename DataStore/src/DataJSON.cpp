/*
*
*
*
*/
 
/*! \file DataJSON.cpp
	\brief A implementation of DataJSON class.
*/
* 
#include "../include/DataJSON.hpp"
#include <iostream>
#include <fstream>
#include "json/json.h" //this file add library for json serialization 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

#include <stdio.h>  /* defines FILENAME_MAX */
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>

#ifdef _WIN32
	#include <direct.h>
	#define GetCurrentDir _getcwd
#elif __linux__
	#include <unistd.h>
	#define GetCurrentDir getcwd
	#include <sys/stat.h>
	#define mkdir(path) mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#else
	#error("Unsuportted OS")
#endif

using namespace std; 

/**********************************************************************************************//**
 * \fn	DataJSON::DataJSON()
 *
 * \brief	Default constructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

DataJSON::DataJSON() {}

/*!
 * @fn	DataJSON::~DataJSON()
 *
 * @brief	Destructor
 *
 * @author	Marcin Dolicher
 * @date	10.06.2019
 */

/**********************************************************************************************//**
 * \fn	DataJSON::~DataJSON()
 *
 * \brief	Destructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

DataJSON::~DataJSON() {}

/**********************************************************************************************//**
 * \fn	string DataJSON::getCurrentWorkingDirectory()
 *
 * \brief	Gets current working directory
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \returns	The current working directory.
 **************************************************************************************************/

string DataJSON::getCurrentWorkingDirectory()
{
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	std::cout << current_working_dir << std::endl;
	return current_working_dir;
}

/**********************************************************************************************//**
 * \fn	ifstream DataJSON::loadJsonFile(string fileName)
 *
 * \brief	Loads JSON file
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param	fileName	Filename of the file.
 *
 * \returns	The JSON file.
 **************************************************************************************************/

ifstream DataJSON::loadJsonFile(string fileName)
{
	
    // #ifdef _WIN32
    //     std::replace( fileName.begin(), fileName.end(), '/', filePathSeparator)
    // #endif
	//string beginOfString = string("./");
	//fileName = beginOfString + fileName;
	std::ifstream data_file(fileName, std::ifstream::in);

	if (data_file.good() == true)
		cout << "I have acces to file" << endl;
	else
		cout << "I don't have acces to file" << endl;
	
	return data_file;
}

/**********************************************************************************************//**
 * \fn	string DataJSON::readJSONFromFile(string fileName)
 *
 * \brief	Reads JSON from file
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param	fileName	Filename of the file.
 *
 * \returns	The JSON from file.
 **************************************************************************************************/

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
			for ( unsigned int i = 0; i < lineToReturn.length(); i++)
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

/**********************************************************************************************//**
 * \fn	void DataJSON::writeJSONToFile(string fileName, MQTT_Data_t &messageFromBroker)
 *
 * \brief	Writes a JSON to file
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param 		  	fileName		 	Filename of the file.
 * \param [in,out]	messageFromBroker	The message from broker.
 **************************************************************************************************/

void DataJSON::writeJSONToFile(string fileName, MQTT_Data_t &messageFromBroker)
{
	string writingPath;
	string currentPath = this->getCurrentWorkingDirectory();
	std::size_t pos = currentPath.find("build");

	// ścieżka do pliku wraz z nazwą message.json
	std::string fileJSONPath;
	ofstream fileJSON;


	currentPath = currentPath.substr(0, pos);
	string directoryDatabase = string("Database");
	currentPath += directoryDatabase;
	cout << "currentPath: " << currentPath <<std::endl;

	//string goOtrzymuje = "/merakimv/Q2HV-6YJL-JGJ4/raw_detections"; //topic
	std::string s = messageFromBroker.topic;

	fileJSONPath = currentPath + s + filePathSeparator + "message.json";
	cout << "fileJSONPath: " << fileJSONPath <<std::endl;
	
    #ifdef _WIN32
	std::replace(s.begin(), s.end(), '/', filePathSeparator);
    #endif
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
			break;
		}

		std::size_t pos = s.find(temp);
		s = s.substr(pos+temp.length());
		cout << "AFTER SUBSTR" << s<<endl;
	}

	fileJSON.open(fileJSONPath, ios::app);
	//fileJSON << "{ \n";
	std::copy(messageFromBroker.dataVector.begin(), messageFromBroker.dataVector.end(),
		std::ostream_iterator<char>(fileJSON, ""));
	//fileJSON << "\n } \n";
	fileJSON << ", \n";
	fileJSON.close();
}

/**********************************************************************************************//**
 * \fn	string DataJSON::getStringForPath(string s)
 *
 * \brief	Gets string for path
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param	s	The string.
 *
 * \returns	The string for path.
 **************************************************************************************************/

string DataJSON::getStringForPath(string s)
{
	std::size_t a;
	std::size_t b;
	string temp;
	a = s.find(filePathSeparator);
	if (a != std::string::npos)
		cout << "A:: " << a << endl;
	b = s.find(filePathSeparator, a + 1);
	if (b != std::string::npos) {
		cout << "B:: " << b << endl;
		temp = s.substr(a, b);
	}
	else {
		temp = s.substr(a);
	}
	return temp;
}

/**********************************************************************************************//**
 * \fn	void DataJSON::replaceFunction()
 *
 * \brief	Replace function
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

void DataJSON::replaceFunction() {
	std::string s = "example string";
	std::replace(s.begin(), s.end(), 'x', 'y'); // replace all 'x' to 'y'
}