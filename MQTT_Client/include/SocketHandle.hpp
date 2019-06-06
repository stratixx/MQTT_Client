#ifndef SOCKETHANDLE_H
#define SOCKETHANDLE_H

#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501  /* Windows XP. */
#endif
#include <winsock2.h>
#include <Ws2tcpip.h>
#else
/* Assume that any non-Windows platform uses POSIX-style sockets instead. */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#include <unistd.h> /* Needed for close() */
#endif

class SocketHandle
{
	
public:
	SocketHandle();
	~SocketHandle();
	int sockInit(void);
	int sockQuit(void);
	int sockClose(SOCKET sock);
};

/*
typedef struct addrinfo {
	int             ai_flags;
	int             ai_family;
	int             ai_socktype;
	int             ai_protocol;
	size_t          ai_addrlen;
	char            *ai_canonname;
	struct sockaddr *ai_addr;
	struct addrinfo *ai_next;
} ADDRINFOA, *PADDRINFOA;
*/
#endif