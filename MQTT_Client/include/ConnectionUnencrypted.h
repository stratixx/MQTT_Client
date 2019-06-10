/*
*
*
*
*/

#ifndef CONNECTION_UNENCRYPTED_H
#define CONNECTION_UNENCRYPTED_H
/*!
* \file ConnectionUnencryoted.h
* \brief Header for functions from unencrypted connection.
*/
#include "Connection.h"

/**********************************************************************************************//**
 * \class	ConnectionUnencrypted
 *
 * \brief	A connection unencrypted.
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

class ConnectionUnencrypted : public Connection
{
    public:

    /**********************************************************************************************//**
     * \fn	bool connect(address_t&, port_t&, options_t&);
     *
     * \brief	Connects
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     * \param [in,out]	parameter2	The second parameter.
     * \param [in,out]	parameter3	The third parameter.
     *
     * \returns	True if it succeeds, false if it fails.
     **************************************************************************************************/

    bool        connect(address_t&, port_t&, options_t&);

    /**********************************************************************************************//**
     * \fn	bool disconnect();
     *
     * \brief	Disconnects this object
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \returns	True if it succeeds, false if it fails.
     **************************************************************************************************/

    bool        disconnect();

    /**********************************************************************************************//**
     * \fn	packet_t& packetFromPayload(payload_t&, packet_t&);
     *
     * \brief	Packet from payload
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     * \param [in,out]	parameter2	The second parameter.
     *
     * \returns	A reference to a packet_t.
     **************************************************************************************************/

    packet_t&   packetFromPayload(payload_t&, packet_t&);

    /**********************************************************************************************//**
     * \fn	payload_t& payloadFromPacket(packet_t&, payload_t&);
     *
     * \brief	Payload from packet
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     * \param [in,out]	parameter2	The second parameter.
     *
     * \returns	A reference to a payload_t.
     **************************************************************************************************/

    payload_t&  payloadFromPacket(packet_t&, payload_t&);

    /**********************************************************************************************//**
     * \fn	bool sendPacket(packet_t&);
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

    bool        sendPacket(packet_t&);

    /**********************************************************************************************//**
     * \fn	packet_t& receivePacket(packet_t&);
     *
     * \brief	Receive packet
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     *
     * \returns	A reference to a packet_t.
     **************************************************************************************************/

    packet_t&   receivePacket(packet_t&);

    /**********************************************************************************************//**
     * \fn	bool sendPayload(payload_t&);
     *
     * \brief	Sends a payload
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     *
     * \returns	True if it succeeds, false if it fails.
     **************************************************************************************************/

    bool        sendPayload(payload_t&);

    /**********************************************************************************************//**
     * \fn	payload_t& receivePayload(payload_t&);
     *
     * \brief	Receive payload
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     *
     * \returns	A reference to a payload_t.
     **************************************************************************************************/

    payload_t&  receivePayload(payload_t&);

    /**********************************************************************************************//**
     * \fn	ConnectionUnencrypted();
     *
     * \brief	Default constructor
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     **************************************************************************************************/

    ConnectionUnencrypted();

    /**********************************************************************************************//**
     * \fn	ConnectionUnencrypted(address_t&, port_t&, options_t&);
     *
     * \brief	Constructor
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \param [in,out]	parameter1	The first parameter.
     * \param [in,out]	parameter2	The second parameter.
     * \param [in,out]	parameter3	The third parameter.
     **************************************************************************************************/

    ConnectionUnencrypted(address_t&, port_t&, options_t&);

    /**********************************************************************************************//**
     * \fn	~ConnectionUnencrypted();
     *
     * \brief	Destructor
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     **************************************************************************************************/

    ~ConnectionUnencrypted();

    private:  


};

#endif //CONNECTION_UNENCRYPTED_H