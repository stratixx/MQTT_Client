#include "../include/SocketHandle.hpp"
#include <boost/smart_ptr.hpp>
#include <string>

/*!
* \file SocketHandle.cpp
* \brief Implementation a mechanism for socket handle
*/

/**********************************************************************************************//**
 * \fn	SocketHandle::SocketHandle()
 *
 * \brief	Default constructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

SocketHandle::SocketHandle()
{

}

/**********************************************************************************************//**
 * \fn	SocketHandle::~SocketHandle()
 *
 * \brief	Destructor
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 **************************************************************************************************/

SocketHandle::~SocketHandle()
{

}

/**********************************************************************************************//**
 * \fn	int sockInit(void)
 *
 * \brief	Sock initialize
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \returns	An int.
 **************************************************************************************************/

int sockInit(void)
{
#ifdef _WIN32
	WSADATA wsa_data;
	return WSAStartup(MAKEWORD(1, 1), &wsa_data);
#else
	return 0;
#endif
}

/**********************************************************************************************//**
 * \fn	int sockQuit(void)
 *
 * \brief	Sock quit
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \returns	An int.
 **************************************************************************************************/

int sockQuit(void)
{
#ifdef _WIN32
	return WSACleanup();
#else
	return 0;
#endif
}

/**********************************************************************************************//**
 * \fn	int sockClose(SOCKET sock)
 *
 * \brief	Sock close
 *
 * \author	Marcin Dolicher
 * \date	10.06.2019
 *
 * \param	sock	The sock.
 *
 * \returns	An int.
 **************************************************************************************************/

int sockClose(SOCKET sock)
{
	int status = 0;

#ifdef _WIN32
	status = shutdown(sock, SD_BOTH);
	if (status == 0) { status = closesocket(sock); }
#else
	status = shutdown(sock, SHUT_RDWR);
	if (status == 0) { status = close(sock); }
#endif

	return status;

}