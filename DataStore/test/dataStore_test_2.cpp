
#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule2
#include <boost/test/unit_test.hpp>
#include "../include/DataStore.hpp"
#include "../include/DataJSON.hpp"

/*! \file dataStore_test_2.cpp
	\brief File with tests for DataStore
*/

BOOST_AUTO_TEST_CASE( test_2 )
{
    using namespace std;

    string pathJSON = "../../DataStore/src/exampleJSON.json";
    #ifdef _WIN32
	std::replace(pathJSON.begin(), pathJSON.end(), '/', filePathSeparator);
    #endif

    cout<<"TestModule2 test_2 "<<endl;
	DataJSON dataJSON;
	ifstream data_file = dataJSON.loadJsonFile(pathJSON);

    BOOST_CHECK(data_file.good() ==true);
	data_file.close();
    
}

// int main()
// {
//     return -1;
// }