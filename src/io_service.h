#ifndef  _IO_SERVICE_H
#define _IO_SERVICE_H
#include "main.h"

class io_service {
	struct sockaddr_in server;
	struct hostent *host_info;
	bool setupNet();

public:
	io_service(argstruct* args);
	sockaddr_in* getSockaddr();
};
#endif