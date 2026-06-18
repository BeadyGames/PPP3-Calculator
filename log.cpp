#include "log.h"
#include <stdexcept>

void error(const char* message)
{
	throw std::runtime_error(message);
}