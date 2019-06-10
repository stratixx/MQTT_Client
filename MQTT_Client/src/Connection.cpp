/*
*
*
*
*/

#include "../include/Connection.h"

/*!
* \file Connection.cpp
* \brief Header of connection file
*/
* 
/**********************************************************************************************//**
 * \fn	Connection::Connection()
 *
 * \brief	Default constructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

Connection::Connection()
{

}

/**********************************************************************************************//**
 * \fn	Connection::Connection(address_t& address_, port_t& port_, options_t& options_)
 *
 * \brief	Constructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	address_	The address.
 * \param [in,out]	port_   	The port.
 * \param [in,out]	options_	Options for controlling the operation.
 **************************************************************************************************/

Connection::Connection(address_t& address_, port_t& port_, options_t& options_)
{
    address = address_;
    port = port_;
    options = options_;
}

/**********************************************************************************************//**
 * \fn	Connection::~Connection()
 *
 * \brief	Destructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

Connection::~Connection()
{
    
}