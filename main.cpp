#include "calculator.h"


/* 
   Program that can calculate complicated expressions using the console window 
   My interest wasn't so much in the calculator from Stroustrup's PPP3 work,
   but in the underlying principles of expression parsing using Tokens.

   I have tried to do as much without reciting the book. Some problems were obvious,
   for example: a buffer was needed to temporarily store a token so the next function could use it.

   Extra features have also been added which are not in the chapter work itself.
*/


// Simply calls calculate() to start the program
int main()
{
	calculate();
}
