#include "log.h"
#include <stdexcept>

void error(const char* message)
{
	throw std::exception(message);
}