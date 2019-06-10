/*
*
*
*
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include<string>

/*!
* \file Connection.h
* \brief Header of connection file 
*/
 
/**********************************************************************************************//**
 * \typedef	std::string address_t
 *
 * \brief	Defines an alias representing the address t
 **************************************************************************************************/

typedef std::string     address_t;

/**********************************************************************************************//**
 * \typedef	int port_t
 *
 * \brief	Defines an alias representing the port
 **************************************************************************************************/

typedef int             port_t;

/**********************************************************************************************//**
 * \typedef	std::string payload_t
 *
 * \brief	Defines an alias representing the payload t
 **************************************************************************************************/

typedef std::string     payload_t;

/**********************************************************************************************//**
 * \typedef	std::string packet_t
 *
 * \brief	Defines an alias representing the packet
 **************************************************************************************************/

typedef std::string     packet_t;

/**********************************************************************************************//**
 * \typedef	std::string options_t
 *
 * \brief	Defines an alias representing the options t
 **************************************************************************************************/

typedef std::string     options_t;

/*

/**********************************************************************************************//**
 * \class	Connection
 *
 * \brief	A connection.
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

class Connection
{
    public:

    /**********************************************************************************************//**
     * \fn	virtual bool connect(address_t&, port_t&, options_t&)=0;
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

    virtual bool        connect(address_t&, port_t&, options_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual bool disconnect()=0;
     *
     * \brief	Disconnects this object
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     *
     * \returns	True if it succeeds, false if it fails.
     **************************************************************************************************/

    virtual bool        disconnect()=0;

    /**********************************************************************************************//**
     * \fn	virtual packet_t& packetFromPayload(payload_t&, packet_t&)=0;
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

    virtual packet_t&   packetFromPayload(payload_t&, packet_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual payload_t& payloadFromPacket(packet_t&, payload_t&)=0;
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

    virtual payload_t&  payloadFromPacket(packet_t&, payload_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual bool sendPacket(packet_t&)=0;
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

    virtual bool        sendPacket(packet_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual packet_t& receivePacket(packet_t&)=0;
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

    virtual packet_t&   receivePacket(packet_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual bool sendPayload(payload_t&)=0;
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

    virtual bool        sendPayload(payload_t&)=0;

    /**********************************************************************************************//**
     * \fn	virtual payload_t& receivePayload(payload_t&)=0;
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

    virtual payload_t&  receivePayload(payload_t&)=0;

    ~Connection();

    protected:
    /** \brief	The address */
    address_t   address;
    /** \brief	The port */
    port_t      port;
    /** \brief	Options for controlling the operation */
    options_t   options;
    
    Connection();
    Connection(address_t&, port_t&, options_t&);


};

#endif //CONNECTION_H