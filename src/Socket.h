#ifndef _SOCKET_H
#define _SOCKET_H
#include "main.h"
#include "io_service.h"

class Socket {
	int sock;
	struct sockaddr_in serv_addr;
public:
	Socket(io_service* service);
	int Connect();
	int Send(const char* buf, int len, int flags);
	int Send(std::string buf, int flags);
	int Close();
};
#endif