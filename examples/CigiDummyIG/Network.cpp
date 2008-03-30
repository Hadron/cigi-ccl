/** <pre>
 *  The Multi-Purpose Viewer
 *  Copyright (c) 2004 The Boeing Company
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *  FILENAME:   Network.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *
 *  PROGRAM DESCRIPTION:
 *  This class contains the data and methods necessary to
 *   handle the network interface.
 *
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *
 *  03/29/2004 Andrew Sampson                       MPV_CR_DR_1
 *  Initial Release.
 *
 *  07/10/2006 Greg Basler                       1.7.2
 *  Corrected a problem with the code that cause a stray
 *  pointer due to the "JUST_IP_ADDRESSES" declaration.
 * </pre>
 *  The Boeing Company
 *  1.7.2
 */


#include "Network.h"

#include <stdio.h>
#include <fcntl.h>
#include <memory.h>

// ================================================
// Network
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Network::Network()
{
	valid = false;
	#ifndef JUST_IP_ADDRESSES
	saddr = NULL;
	#endif
}

// ================================================
// ~Network
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Network::~Network()
{
	closeSocket();
	#ifndef JUST_IP_ADDRESSES
	freeaddrinfo(saddr);
	#endif
}

// ================================================
// openSocket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool Network::openSocket( const char * ip, const int port_send, const int port_rcv )
{
	// Initialize communications.
	InitializeComm(ip, port_send, port_rcv);

	return valid;
}

// ================================================
// openSocket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool Network::openSocket(const int port_rcv )
{
	// Initialize communications.
	InitializeComm(port_rcv);

	return valid;
}


// ================================================
// closeSocket
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Network::closeSocket()
{
	if( !valid ) return;


#ifdef WIN32
	// Clean up the sockets.
	closesocket(sndsock);
	closesocket(rcvsock);

   // Clean up WinSock.  Again, this is not needed for non-Windows platforms.
	WSACleanup();
#else

	// Clean up the sockets.
	close(sndsock);
	close(rcvsock);

#endif

	valid = false;
}


// ================================================
// send
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int Network::send( unsigned char * sendbuff, int sendsize )
{
	if( !valid) return -1;

	#ifdef JUST_IP_ADDRESSES
	if(!saddr.sin_family ) return -1;
	return sendto(sndsock, (const char *)sendbuff, sendsize, 0, (struct sockaddr *)&saddr,
			sizeof(struct sockaddr));
	#else
	if(!saddr) return -1;
	return sendto(sndsock, (const char *)sendbuff, sendsize, 0,
		saddr->ai_addr, saddr->ai_addrlen);
	#endif // JUST_IP_ADDRESSES


}

// ================================================
// recv
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
int Network::recv( unsigned char * rcvbuff, int recvsize )
{
	if( !valid ) return -1;
	return recvfrom(rcvsock, (char *)rcvbuff, recvsize, 0, NULL, 0);
}



// ================================================
// InitializeComm
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Network::InitializeComm(const char *ipaddr, const int sndport, const int rcvport)
{
	int status;

#ifdef WIN32
	// Initialize winsock.  If you are using Berkeley sockets on a
	// non-Win32 platform, you can leave out these first two lines.
	WSADATA wsainfo;
	WSAStartup(MAKEWORD(1, 1), &wsainfo);
#endif

	// Open the connection for sending.

#ifdef JUST_IP_ADDRESSES
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(sndport);	// Use whatever port your host listens on
	saddr.sin_addr.s_addr = inet_addr(ipaddr);	// IP address of host

	sndsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( sndsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}
#else
	if(saddr)
	{
		freeaddrinfo(saddr);
		saddr = NULL;
	}

	char portstr[6];
	snprintf(portstr, sizeof(portstr), "%u", sndport);
	struct addrinfo hint;
	hint.ai_flags = 0;
	//hint.ai_family = AF_INET | AF_INET6;
	hint.ai_family = AF_UNSPEC;
	hint.ai_socktype = SOCK_DGRAM;
	hint.ai_protocol = IPPROTO_UDP;
	hint.ai_addrlen = 0;
	hint.ai_addr = NULL;
	hint.ai_canonname = NULL;
	hint.ai_next = NULL;
	int result = getaddrinfo(ipaddr, portstr, &hint, &saddr);
	if(result)
	{
		if(saddr)
		{
			freeaddrinfo(saddr);
			saddr = NULL;
		}
		return;
	}
	sndsock = socket(saddr->ai_family, saddr->ai_socktype,
		saddr->ai_protocol);
#endif // JUST_IP_ADDRESSES

	// Open the connection for receiving.
   memset(&raddr,0,sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(rcvport);	// Use whatever port your host sends to
	raddr.sin_addr.s_addr = htonl(INADDR_ANY);

	rcvsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( rcvsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}

	// Make the address reusable.
	int sockparam = 1; /* TRUE; */
	setsockopt(rcvsock, SOL_SOCKET, SO_REUSEADDR, (const char *)&sockparam, sizeof(int));

	// Make the socket non-blocking.
#ifdef WIN32
	// This is how sockets are put in non-blocking mode on Windows.
	unsigned long arg = 1L;
	ioctlsocket(rcvsock, FIONBIO, &arg);
#else
	// This is how sockets are put in non-blocking mode on non-Windows operating systems (and Cygwin).
	fcntl( rcvsock, F_SETFL, O_NONBLOCK );
#endif

	// Bind the socket to the local address.
	status =
		bind(rcvsock, (struct sockaddr *)&raddr, sizeof(raddr));
	if( status != 0 ) {
		// socket could not be bound
		valid = false;
		return;
	}


	// FIXME - more error checking
	valid = true;
}

// ================================================
// InitializeComm
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Network::InitializeComm(const int rcvport)
{
	int status;

#ifdef WIN32
	// Initialize winsock.  If you are using Berkeley sockets on a
	// non-Win32 platform, you can leave out these first two lines.
	WSADATA wsainfo;
	WSAStartup(MAKEWORD(1, 1), &wsainfo);
#endif

	sndsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( sndsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}

	// Disable sending.
#ifdef JUST_IP_ADDRESSES
	saddr.sin_family = 0;
#else
	if(saddr)
	{
		freeaddrinfo(saddr);
		saddr = NULL;
	}
#endif // JUST_IP_ADDRESSES

	// Open the connection for receiving.
   memset(&raddr,0,sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(rcvport);	// Use whatever port your host sends to
	raddr.sin_addr.s_addr = htonl(INADDR_ANY);

	rcvsock = socket(AF_INET, SOCK_DGRAM, 0);
	if( rcvsock < 0 ) {
		// socket could not be created
		valid = false;
		return;
	}

	// Make the address reusable.
	int sockparam = 1; /* TRUE; */
	setsockopt(rcvsock, SOL_SOCKET, SO_REUSEADDR, (const char *)&sockparam, sizeof(int));

	// Make the socket non-blocking.
#ifdef WIN32
	// This is how sockets are put in non-blocking mode on Windows.
	unsigned long arg = 1L;
	ioctlsocket(rcvsock, FIONBIO, &arg);
#else
	// This is how sockets are put in non-blocking mode on non-Windows operating systems (and Cygwin).
	fcntl( rcvsock, F_SETFL, O_NONBLOCK );
#endif

	// Bind the socket to the local address.
	status =
		bind(rcvsock, (struct sockaddr *)&raddr, sizeof(raddr));
	if( status != 0 ) {
		// socket could not be bound
		valid = false;
		return;
	}


	// FIXME - more error checking
	valid = true;
}
