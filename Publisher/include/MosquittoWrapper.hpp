/*
*
*
*
*/

#include <mosquittopp.h>

#ifndef MOSQUITTOWRAPPER_H
#define MOSQUITTOWRAPPER_H

class MosquittoWrapper : public mosqpp::mosquittopp
{
private:
	const char     *     host;
	const char    *     id;
	const char    *     topic;
	int                port;
	int                keepalive;

	void on_connect(int rc);
	void on_disconnect(int rc);
	void on_publish(int mid);
public:
	MosquittoWrapper(const char *id, const char * _topic, const char *host, int port);
	~MosquittoWrapper();
	bool send_message(const char * _message);
};


#endif