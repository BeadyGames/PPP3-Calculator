#include "calculator.h"
#include "token.h"
#include "log.h"

/****** Basic Grammar Rules ******/
/*
* Expression:
		 Term
		 Expression + Term
		 Expression - Term
* Term:
		 Primary
		 Term * Primary
		 Term / Primary
* Primary:
		 Number
		 ( Expression )
		 - Primary
		 + Primary
*/


// Deals with addition and subtraction
// Calls term() to handle multiplication and division first
double expression(Token_stream& ts)
{
	double val = term(ts);

	while (true)
	{
		Token t = ts.get();

		switch (t.kind)
		{
		case '+':
			val += term(ts);  // Expression '+' Term rule
			break;

		case '-':
			val -= term(ts); // Expression '-' Term rule
			break;

		default:
			ts.putback(t);
			return val;
		}
	}
}

// Deals with multiplication and division
// Checks for division by zero
double term(Token_stream& ts)
{
	double val = primary(ts);

	while (true)
	{
		Token t = ts.get();

		switch (t.kind)
		{
		case '*':
			val *= primary(ts);  // Term '*' Primary rule
			break;

		case '/':
		{
			double d = primary(ts);
			if (d == 0)
			{
				error("Error: Division by zero inside term()");
			}
			val /= d;      // Term '/' Primary rule
			break;
		}

		default:
			ts.putback(t);   // Put t back into the token stream
			return val;
		}
	}
}

// Deals with numbers and parentheses
// Expressions normally start with a number or opening bracket
double primary(Token_stream& ts)
{
	Token t = ts.get();

	switch (t.kind)
	{
	case '(':
	{
		double val = expression(ts);
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