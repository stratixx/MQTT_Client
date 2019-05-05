
#include <iostream>
#define BOOST_TEST_MODULE DataStoreTestModule2
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test_2 )
{
    using namespace std;

    cout<<"TestModule2 test_2 "<<endl;

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }