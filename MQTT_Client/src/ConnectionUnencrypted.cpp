/*
*
*
*
*/

#include "../include/ConnectionUnencrypted.h"

/*!
* \file ConnectionUnencryoted.cpp
* \brief Implementation functions for unencrypted connection.
*/

/**********************************************************************************************//**
 * \fn	bool ConnectionUnencrypted::connect(address_t& address_, port_t& port_, options_t& options_)
 *
 * \brief	Connects
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	address_	The address.
 * \param [in,out]	port_   	The port.
 * \param [in,out]	options_	Options for controlling the operation.
 *
 * \returns	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool ConnectionUnencrypted::connect(address_t& address_, port_t& port_, options_t& options_)
{
    return false;
}

/**********************************************************************************************//**
 * \fn	bool ConnectionUnencrypted::disconnect()
 *
 * \brief	Disconnects this object
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \returns	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool ConnectionUnencrypted::disconnect()
{
    return false;
}

/**********************************************************************************************//**
 * \fn	packet_t& ConnectionUnencrypted::packetFromPayload(payload_t& payload, packet_t& packet)
 *
 * \brief	Packet from payload
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	payload	The payload.
 * \param [in,out]	packet 	The packet.
 *
 * \returns	A reference to a packet_t.
 **************************************************************************************************/

packet_t& ConnectionUnencrypted::packetFromPayload(payload_t& payload, packet_t& packet)
{
    return packet; 
}

/**********************************************************************************************//**
 * \fn	payload_t& ConnectionUnencrypted::payloadFromPacket(packet_t&, payload_t& payload)
 *
 * \brief	Payload from packet
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	parameter1	The first parameter.
 * \param [in,out]	payload   	The payload.
 *
 * \returns	A reference to a payload_t.
 **************************************************************************************************/

payload_t&  ConnectionUnencrypted::payloadFromPacket(packet_t&, payload_t& payload)
{
    return payload;
}

/**********************************************************************************************//**
 * \fn	bool ConnectionUnencrypted::sendPacket(packet_t&)
 *
 * \brief	Sends a packet
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	parameter1	The first parameter.
 *
 * \returns	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool ConnectionUnencrypted::sendPacket(packet_t&)
{
    return false;
}

/**********************************************************************************************//**
 * \fn	packet_t& ConnectionUnencrypted::receivePacket(packet_t& packet)
 *
 * \brief	Receive packet
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	packet	The packet.
 *
 * \returns	A reference to a packet_t.
 **************************************************************************************************/
packet_t& ConnectionUnencrypted::receivePacket(packet_t& packet)
{
    return packet;
}

/**********************************************************************************************//**
 * \fn	bool ConnectionUnencrypted::sendPayload(payload_t& payload)
 *
 * \brief	Sends a payload
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	payload	The payload.
 *
 * \returns	True if it succeeds, false if it fails.
 **************************************************************************************************/

bool ConnectionUnencrypted::sendPayload(payload_t& payload)
{
    packet_t packet;

    return sendPacket(packetFromPayload(payload, packet));
}

/**********************************************************************************************//**
 * \fn	payload_t& ConnectionUnencrypted::receivePayload(payload_t& payload)
 *
 * \brief	Receive payload
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param [in,out]	payload	The payload.
 *
 * \returns	A reference to a payload_t.
 **************************************************************************************************/
payload_t& ConnectionUnencrypted::receivePayload(payload_t& payload)
{
    packet_t packet;
    return payloadFromPacket(receivePacket(packet), payload);
}

/**********************************************************************************************//**
 * \fn	ConnectionUnencrypted::ConnectionUnencrypted()
 *
 * \brief	Default constructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

ConnectionUnencrypted::ConnectionUnencrypted() : 
    Connection()
{

}

/**********************************************************************************************//**
 * \fn	ConnectionUnencrypted::ConnectionUnencrypted(address_t& address_, port_t& port_, options_t& options_)
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
ConnectionUnencrypted::ConnectionUnencrypted(address_t& address_, port_t& port_, options_t& options_) : 
    Connection(address_, port_, options_)
{

}

/**********************************************************************************************//**
 * \fn	ConnectionUnencrypted::~ConnectionUnencrypted()
 *
 * \brief	Destructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

ConnectionUnencrypted::~ConnectionUnencrypted()
{
    
}
