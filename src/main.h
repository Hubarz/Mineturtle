#ifndef _MAIN_H
#define _MAIN_H
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#ifdef _WIN32
#include "windows.h"
#include <winsock.h>
#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "Winmm.lib")
#define _close closesocket
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#define _close close
#endif
#define version "0.2"

struct argstruct {
	std::string address;
	std::string userAgent;
	int port;
	short connections;
	short threads;
	int seconds;
	bool simProxy;
	bool test;
};
void wait(int seconds);
#endif
