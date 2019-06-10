
#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule3
#include <boost/test/unit_test.hpp>
#include "../include/DataStore.hpp"
#include "../include/DataJSON.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

/*! \file dataStore_test_3.cpp
	\brief File with tests for DataStore
*/

BOOST_AUTO_TEST_CASE( test_3 )
{
    using namespace std;

    cout<<"TestModule3 test_3 "<<endl;
	DataJSON dataJSON;
	boost::property_tree::ptree jsontree;
	string returnedString;
	string toSend = string("exampleJSON2.json");
	ifstream data_file = dataJSON.loadJsonFile(toSend);
	//cout << data_file << endl;
	/*boost::property_tree::read_json(data_file, jsontree);
	int v0 = jsontree.get<int>("a");
	int v1 = jsontree.get<int>("c");

	const boost::property_tree::ptree& b = jsontree.get_child("b");
	for (const auto& kv : b) {
		cout << "b_b_a = " << kv.second.get<string>("b_b.b_b_a") << "\n";
		returnedString = kv.second.get<string>("b_b.b_b_a");
	}
	string test = string("test");
	cout << returnedString << endl;
    BOOST_CHECK(returnedString == test);*/

	data_file.close();
}

// int main()
// {
//     return -1;
// }