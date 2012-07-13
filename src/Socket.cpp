#include "main.h"
#include "io_service.h"
#include "Socket.h"
#include "Exception.h"

Socket::Socket(io_service* service) {
	this->serv_addr=*service->getSockaddr();
	this->sock=socket(PF_INET, SOCK_STREAM, 0);
	if(this->sock==-1) throw Exception("Can't create socket.");
}

int Socket::Connect() {
	return (connect(this->sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)));
}

int Socket::Send(const char* buf, int len, int flags) {
	return (send(sock, buf, len, flags));
}

int Socket::Close() {
	return _close(sock);
}

int Socket::Send(std::string buf, int flags) {
	return (send(sock, buf.c_str(), buf.size(), flags));
}
