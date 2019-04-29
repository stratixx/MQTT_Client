/*
*
*
*
*/

#include "../include/Connection.h"


Connection::Connection()
{

}

Connection::Connection(address_t& address_, port_t& port_, options_t& options_)
{
    address = address_;
    port = port_;
    options = options_;
}

Connection::~Connection()
{
    
}