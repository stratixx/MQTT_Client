
#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule2
#include <boost/test/unit_test.hpp>
#include "../include/DataStore.hpp"
#include "../include/DataJSON.hpp"

BOOST_AUTO_TEST_CASE( test_2 )
{
    using namespace std;

    cout<<"TestModule2 test_2 "<<endl;
	DataJSON dataJSON;
	ifstream data_file = dataJSON.loadJsonFile("exampleJSON.json");

    BOOST_CHECK(data_file.good() ==true);
	data_file.close();
    
}

// int main()
// {
//     return -1;
// }