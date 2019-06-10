
#include <iostream>
#define BOOST_TEST_MODULE TestModule2
#include <boost/test/unit_test.hpp>

/*!
	\file subscriber_test_2.cpp
	\brief File with tests for Subscriber
*/

BOOST_AUTO_TEST_CASE( test_2 )
{
    using namespace std;

    cout<<"TestModule1 test_2 "<<endl;

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }