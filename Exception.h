#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>
#include<string>

struct ExceptionCustom final : std::runtime_error {
	explicit ExceptionCustom (const char* msg) : std::runtime_error(msg) {}
	explicit ExceptionCustom (const std::string& msg) : std::runtime_error(msg) {}
};

#endif 