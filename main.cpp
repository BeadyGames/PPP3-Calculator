#include <iostream>
#include "token.h"
#include "calculator.h"
#include "log.h"

/* 
   Program that can calculate complicated expressions using the console window 
   My interest wasn't so much in the calculator from Stroustrup's PPP3 work,
   but in the underlying principles of expression parsing using Tokens.

   I have tried to do as much without reciting the book. Some problems were obvious,
   for example: a buffer was needed to temporarily store a token so the next function could use it.

   Extra features have also been added which are not in the chapter work itself.
*/

// Deals with printing the result
// The program terminates when an error occurs (i'll get round to this matter!)
int main()
try
{
	while (std::cin)
	{

		Token_stream ts;

		double val = expression(ts);

		Token t = ts.get();
		if (t.kind == print)
		{
			std::cout << "Result: " << val << '\n';
		}
		else if (t.kind == quit)
		{
			break;
		}
		else
		{
			error("Error: Expected '=' or 'e' inside main()");
		}
	}
}
catch (const std::exception& e)
{
	std::cerr << e.what() << '\n';
	return -1;
}