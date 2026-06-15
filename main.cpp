#include <iostream>

/* Program that can calculate complicated expressions using the console window */

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
		std::cerr << "Error: Invalid token!\n";
		return Token('?');
	}
}

void Token_stream::putback(Token t)
{
	if (full)
	{
		std::cerr << "Error: Buffer is full!\n";
	}
	buffer = t;   // put token into buffer
	full = true;  // OK, buffer is now full
}

Token_stream ts; // provides get() and putback()

double expression(); // declaration so that primary() can call expression()	

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
				std::cerr << "Error: Expected ')'!" << '\n';
				return -1; // return an error value for now
			}
			return val;
		}

		case number:
			return t.value;

		default:
			std::cerr << "Error: Expected a primary!" << '\n';
			return -1; // return an error value for now
	}
}

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
				std::cerr << "Error: Division by zero!" << '\n';
				return -1; // return an error value for now
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
			std::cerr << "Error: Expected '=' or 'e'!" << '\n';
			return -1; // return an error value for now
		}
	}
}