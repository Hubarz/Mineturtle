#include "main.h"
#include "io_service.h"
#include "Socket.h"
#include "Exception.h"
#include "worker.h"
#include <ctime>
int testCon(io_service* io_service, std::string host);
bool parseArgs(int argc, char* argv[], argstruct* args);

int main(int argc, char* argv[]) {
	try	{
		srand((unsigned int)time(NULL));
		argstruct args;
		std::cout << "Welcome to Mineturtle " << version << "!" << std::endl;
		if(!parseArgs(argc, argv, &args)) return 0;
		/* Network things */
		io_service io_service(&args);
		if(args.test) testCon(&io_service, args.address);
		else {
			std::vector<worker> threads;
			for(int i=0; i<args.threads; i++) threads.push_back(worker(&io_service, &args, i));
			for(unsigned int i=0; i<threads.size(); i++) threads[i].start();
			for(unsigned int i=0; i<threads.size(); i++) threads[i].join();
		}
	} catch (Exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
		return 1;
	}
	return 0;
}

void wait(int seconds) 
{ 
#ifdef _WIN32
	Sleep(seconds*1000);
#else
	sleep(seconds);
#endif
}
