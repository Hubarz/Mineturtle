#include "main.h"
#include "io_service.h"
#include "Socket.h"
#include "misc.h"
#include "Exception.h"
int testCon(io_service* io_service, std::string host) {
	int open=0;
	Socket socket(io_service);
	if(socket.Connect()) throw Exception("Can't connect");
	std::string request;
	request = "POST / HTTP/1.1\r\n";
	request += "User-Agent: Opera/9.80 (Windows NT 6.1; U; de) Presto/2.10.229 Version/11.61\r\n";
	request += "Connection: Keep-Alive\r\n";
	request += "Host: "+host+"\r\n";
	request += "Content-Length: 2482\r\n";
	socket.Send(request, 0);
	std::cout << "Connection open since " << open << " seconds." << std::flush;
	for(;;) {
		request = "X-"+misc::randString(10)+": "+misc::randString(10)+"\r\n";
#ifdef _WIN32
		int o = socket.Send(request, 0);
#else
		int o = socket.Send(request, MSG_NOSIGNAL);
#endif
		if (o>0) { //Open
			open++;
			std::cout << "\rConnection open since " << open << " seconds. (" << o << ")" << std::flush;
			wait(1);
		} else { //Closed
			std::cout << "\rThe server closed the connection after " << open << " seconds." << std::endl;
			return open;
		}
	}
	std::cout << "\nmuhahaha" << std::endl;
}
