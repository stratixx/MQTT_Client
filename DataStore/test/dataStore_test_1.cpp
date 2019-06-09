#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule1
#include <boost/test/unit_test.hpp>
#include "../include/DataStore.hpp"
#include "../include/DataJSON.hpp"

using namespace DataStore_NS;

BOOST_AUTO_TEST_CASE( test_1 )
{
    using namespace std;

    cout<<"TestModule1 test_1 "<<endl;
	string currentPath;
	DataJSON dataJSON;
	currentPath = dataJSON.getCurrentWorkingDirectory();
	size_t pos = currentPath.find("MQTT_Client");
	currentPath = currentPath.substr(pos);
	string rightPath = string("MQTT_Client\\build\\DataStore");
	BOOST_TEST(currentPath==rightPath);

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }