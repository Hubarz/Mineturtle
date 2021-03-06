#include "main.h"

void help() {
	std::cout << "Possible arguments: " << std::endl;
	std::cout << "  -help: Shows this message.\n";
	std::cout << "  -test: Switch to test mode to find out the optimal value for -t\n";
	std::cout << "  -h: Hostname or IP address.\n";
	std::cout << "  -p: Port. DEFAULT: 80\n";
	std::cout << "  -c: Count of connections. DEFAULT: 1000\n";
	std::cout << "  -t: Time to hold each connection. (Find out with -test). DEFAULT: 30\n";
	std::cout << "  -u: User-Agent string to use. DEFAULT: A randomly chosen string out of a list of browsers.\n";
	std::cout << "Example 1: ./mineturtle -h example.com -c 500 -t 25\n";
	std::cout << "Example 2: ./mineturtle -h example.com -p 80 -test\n";
	std::cout << "For more info consult https://github.com/Hubarz/Mineturtle" << std::endl;
}

bool parseArgs(int argc, char* argv[], argstruct* args) {
	if(argc<2) {
		help();
		return false;
	}
	args->test=false;
	args->port=80;
	args->connections=1000;
	args->seconds=30;
	args->simProxy=true;
	for(int i=1; i<argc; i++) {
		if(strcmp(argv[i], "-help")==0) {
			help();
			return false;
		} else if(strcmp(argv[i], "-h")==0) {
			args->address=argv[i+1];
		} else if(strcmp(argv[i], "-p")==0) {
			if(atoi(argv[i+1])<1) {
				help();
				return false;
			} else args->port=atoi(argv[i+1]);
		} else if(strcmp(argv[i], "-c")==0) {
			if(atoi(argv[i+1])<1) {
				help();
				return false;
			} else args->connections=atoi(argv[i+1]);
		} else if(strcmp(argv[i], "-test")==0) {
			args->test=true;
		} else if(strcmp(argv[i], "-t")==0) {
			if(atoi(argv[i+1])<1) {
				help();
				return false;
			} else args->seconds=atoi(argv[i+1]);
		} else if(strcmp(argv[i], "-u")==0) {
			args->userAgent=argv[i+1];
		}
	}
	if(args->address=="") {
		help();
		return false;
	}
	args->threads=(args->connections/10);
	return true;
}
