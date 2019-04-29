/*
*
*
*
*/

#ifndef CONNECTION_UNENCRYPTED_H
#define CONNECTION_UNENCRYPTED_H

#include "Connection.h"
/*
*
*
*/
class ConnectionUnencrypted : public Connection
{
    public:

    bool        connect(address_t&, port_t&, options_t&);
    bool        disconnect();
    packet_t&   packetFromPayload(payload_t&, packet_t&);
    payload_t&  payloadFromPacket(packet_t&, payload_t&);
    bool        sendPacket(packet_t&);
    packet_t&   receivePacket(packet_t&);
    bool        sendPayload(payload_t&);
    payload_t&  receivePayload(payload_t&);

    ConnectionUnencrypted();
    ConnectionUnencrypted(address_t&, port_t&, options_t&);
    ~ConnectionUnencrypted();

    private:  


};

#endif //CONNECTION_UNENCRYPTED_H