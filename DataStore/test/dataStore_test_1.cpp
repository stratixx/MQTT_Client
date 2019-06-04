#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule1
#include <boost/test/unit_test.hpp>
#include "../include/DataStore.hpp"

using namespace DataStore_NS;

BOOST_AUTO_TEST_CASE( test_1 )
{
    using namespace std;

    cout<<"TestModule1 test_1 "<<endl;
	DataStore dataJSON;
	//dataJSON->readJSONFromFile("exampleJSON.json");

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }