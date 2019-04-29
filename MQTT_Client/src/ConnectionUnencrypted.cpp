/*
*
*
*
*/

#include "../include/ConnectionUnencrypted.h"

/*
*
*/
bool ConnectionUnencrypted::connect(address_t& address_, port_t& port_, options_t& options_)
{
    return false;
}

/*
*
*/
bool ConnectionUnencrypted::disconnect()
{
    return false;
}

/*
*
*/
packet_t& ConnectionUnencrypted::packetFromPayload(payload_t& payload, packet_t& packet)
{
    return packet; 
}

/*
*
*/
payload_t&  ConnectionUnencrypted::payloadFromPacket(packet_t&, payload_t& payload)
{
    return payload;
}

/*
*
*/
bool ConnectionUnencrypted::sendPacket(packet_t&)
{
    return false;
}

/*
*
*/
packet_t& ConnectionUnencrypted::receivePacket(packet_t& packet)
{
    return packet;
}

/*
*
*/
bool ConnectionUnencrypted::sendPayload(payload_t& payload)
{
    packet_t packet;

    return sendPacket(packetFromPayload(payload, packet));
}

/*
*
*/
payload_t& ConnectionUnencrypted::receivePayload(payload_t& payload)
{
    packet_t packet;
    return payloadFromPacket(receivePacket(packet), payload);
}

/*
*
*/
ConnectionUnencrypted::ConnectionUnencrypted() : 
    Connection()
{

}

/*
*
*/
ConnectionUnencrypted::ConnectionUnencrypted(address_t& address_, port_t& port_, options_t& options_) : 
    Connection(address_, port_, options_)
{

}

/*
*
*/
ConnectionUnencrypted::~ConnectionUnencrypted()
{
    
}
