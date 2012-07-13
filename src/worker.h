/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
| I know class file isn't clean. But it works :D											|
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef _WORKER_H
#define _WORKER_H
#include "main.h"
#include "io_service.h"

struct params {
	io_service* _service;
	argstruct* _args;
	int number;
};

class worker {
	struct params para;
#ifdef _WIN32
	HANDLE thread;
#else
	pthread_t thread;
#endif
public:
	void start();
	void join();
	worker(io_service* _service, argstruct* _args, int number);
};
#endif
