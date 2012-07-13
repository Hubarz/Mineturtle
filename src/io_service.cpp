#include "main.h"
#include "io_service.h"
#include "Socket.h"
#include "Exception.h"

bool io_service::setupNet() {
#ifdef _WIN32
	short wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD (2,2);
	if (WSAStartup (wVersionRequested, &wsaData) != 0) return false;
#endif
	return true;
}

io_service::io_service(argstruct* args) {
	if(!this->setupNet()) throw Exception("Can't start Winsock!");;
	unsigned long addr;
	memset( &this->server, 0, sizeof (this->server));
	if ((addr = inet_addr(args->address.c_str())) != INADDR_NONE) memcpy((char*)&this->server.sin_addr, &addr, sizeof(addr));
	else {
		this->host_info=gethostbyname(args->address.c_str());
		if(host_info==NULL) throw Exception("Can't retrieve the hostname!");
		memcpy((char*)&this->server.sin_addr, this->host_info->h_addr, this->host_info->h_length);
	}
	this->server.sin_family = AF_INET;
	this->server.sin_port = htons(args->port);
	return;
}

sockaddr_in* io_service::getSockaddr() {
	return &this->server;
}