
#include <iostream>
#define BOOST_TEST_MODULE TestModule1
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( test_1 )
{
    using namespace std;

    cout<<"TestModule1 test_1 "<<endl;

    BOOST_CHECK(true);
    
}



// int main()
// {
//     return -1;
// }