#include <iostream>
#include "token.h"
#include "log.h"

// Gives Tokens (numbers, operators, parentheses) and checks input stream
Token Token_stream::get()
{
	// Is there a Token in the buffer?
	if (full)
	{
		full = false;    // empty the buffer
		return buffer;
	}

	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case print:
	case quit:
		return Token(ch);

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return Token(number, val);
	}

	default:
		error("Error: Bad token in get()");
		return -1; // to avoid compiler warning about no return
	}
}

// Puts a Token back into the buffer if not full
void Token_stream::putback(Token t)
{
	if (full)
	{
		error("Error: Buffer is full in putback()");   // Not ideal, but will do for now
	}
	buffer = t;   // Put token into buffer
	full = true;  // OK, buffer is now full
}