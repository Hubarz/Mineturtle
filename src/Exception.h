#ifndef _EXCEPTION_H
#define _EXCEPTION_H
#include "main.h"

class Exception {
	std::string message;
public:
	std::string what() { return this->message; }
	Exception(const char* m) { this->message=m; }
};
#endif