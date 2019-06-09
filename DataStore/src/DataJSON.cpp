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

#include <stdio.h>  /* defines FILENAME_MAX */
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>


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

void DataJSON::readJSONFromFile(string fileName)
{
	try {
		boost::property_tree::ptree jsontree;
		
		ifstream data_file = loadJsonFile(fileName);

		boost::property_tree::read_json(data_file, jsontree);
		int v0 = jsontree.get<int>("a");
		int v1 = jsontree.get<int>("c");


		const boost::property_tree::ptree& b = jsontree.get_child("b");
		for (const auto& kv : b) {
			cout << "b_b_a = " << kv.second.get<string>("b_b.b_b_a") << "\n";
		}

		
		string jsonInString;
		string stringTemp;

		BOOST_FOREACH(boost::property_tree::ptree::value_type &v, jsontree) { // iterate over immediate children of the root
			stringTemp = v.first.data(); // use the converting path getter
			//if(jsontree.get_child(stringTemp)!=NULL)
			//	;
			//boost::property_tree::ptree& childTree = jsontree.get_child();
			
			cout << stringTemp<<endl;
										  //players.push_back(pid);
		}

		//std::ostringstream oss;		
		/*boost::property_tree::ini_parser::write_ini(oss, jsontree);
		std::string inifile_text = oss.str();
		cout << "IIIIIIIIIIIIIIII" << inifile_text << endl;
		*/

		/*std::string xmlFile;
		boost::property_tree::write_xml(xmlFile, jsontree);
		cout << xmlFile;*/

		//boost::property_tree::xml_writer_settings<char> settings('\t', 1);
		boost::property_tree::write_xml("file2.xml", jsontree);// , std::locale(), settings);
		string line;
		ifstream in("file2.xml");

		bool begin_tag = false;
		while (getline(in, line))
		{
			std::string tmp; // strip whitespaces from the beginning
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ' && tmp.size() == 0)
				{
				}
				else
				{
					tmp += line[i];
				}
			}
		}
		
		cout << "line: " << line << endl;
		data_file.close();
	}
	catch (boost::property_tree::json_parser::json_parser_error) {
		cout << "Error by reading a file" << endl;
		return;
	}

	cout << "The file was load" << endl;
}

/*void DataJSON::writeJSONToFile(string fileName, MQTTdata data)
{
	Json::Value root;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "\t";
	std::string document = Json::writeString(wbuilder, root);
	std::ofstream output_file(fileName);
	output_file << document;
	output_file.close();
}
*/
/*int main()
{
	DataJSON *dataJSON = new DataJSON();
	dataJSON->readJSONFromFile("exampleJSON2");

}*/