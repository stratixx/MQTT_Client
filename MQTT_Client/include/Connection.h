/*
*
*
*
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include<string>

typedef std::string     address_t;
typedef int             port_t;
typedef std::string     payload_t;
typedef std::string     packet_t;
typedef std::string     options_t;

/*
*
*
*/
class Connection
{
    public:


    virtual bool        connect(address_t&, port_t&, options_t&)=0;
    virtual bool        disconnect()=0;
    virtual packet_t&   packetFromPayload(payload_t&, packet_t&)=0;
    virtual payload_t&  payloadFromPacket(packet_t&, payload_t&)=0;
    virtual bool        sendPacket(packet_t&)=0;
    virtual packet_t&   receivePacket(packet_t&)=0;
    virtual bool        sendPayload(payload_t&)=0;
    virtual payload_t&  receivePayload(payload_t&)=0;

    ~Connection();

    protected:
    address_t   address;
    port_t      port;
    options_t   options;
    
    Connection();
    Connection(address_t&, port_t&, options_t&);


};

#endif //CONNECTION_H