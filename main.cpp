#include <iostream>
#include <stdexcept>
#include <string>

/* Program that can calculate complicated expressions using the console window */

// Simple error function rather than returning ambiguous error values
void error(std::string message)
{
	throw std::runtime_error(message);
}

const char number = '8'; // kind for numbers
const char quit = 'e'; // 'e' for "quit"
const char print = '='; // '=' for "print"

struct Token
{
	char kind; // what kind of token
	double value; // for numbers: a value

	Token(char k) : kind(k), value(0) {} 
	Token(char k, double val) : kind(k), value(val) {}    // we still need a "kind" to represent a number
};

// Manage the input stream and provide tokens
class Token_stream
{
public:
	Token get();
	void putback(Token t);

private:
	Token buffer{ 0 };
	bool full{ false };
};

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
	}
}

// Puts a Token back into the buffer if not full
void Token_stream::putback(Token t)
{
	if (full)
	{
		error("Error: Buffer is full in putback()");   // Not ideal, but will do for now
	}
	buffer = t;   // put token into buffer
	full = true;  // OK, buffer is now full
}

Token_stream ts; // provides get() and putback()

double expression(); // declaration so that primary() can call expression()	

// Deals with numbers and parentheses
// Expressions genuinely start with a number or parentheses
double primary()
{
	Token t = ts.get();

	switch (t.kind)
	{
		case '(':	
		{
			double val = expression();
			t = ts.get();
			if (t.kind != ')')
			{
				error("Error: Expected ')' inside primary()");
			}
			return val;
		}

		case number:
			return t.value;

		default:
			error("Error: Expected a primary inside primary()");
	}
}

// Deals with multiplication and division
// Checks for division by zero
double term()
{
	double val = primary();

	while (true)
	{
		Token t = ts.get();

		switch (t.kind)
		{
		case '*':
			val *= primary();
			break;

		case '/':
		{
			double d = primary();
			if (d == 0)
			{
				error("Error: Division by zero inside term()");
			}
			val /= d;
			break;
		}

		default:
			ts.putback(t);
			return val;
		}
	}
}

// Deals with addition and subtraction
// Calls term() to handle multiplication and division first
double expression()
{
	double val = term();

	while (true)
	{
		Token t = ts.get();

		switch (t.kind)
		{
		case '+':
			val += term();
			break;

		case '-':
			val -= term();
			break;

		default:
			ts.putback(t);
			return val;
		}
	}
}

int main()
try
{
	while (std::cin)
	{
		double val = expression();

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