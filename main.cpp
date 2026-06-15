#include <iostream>
#include <vector>

/* Program that can calculate complicated expressions using the console window */

struct Token
{
	char kind; // what kind of token
	double value; // for numbers: a value

	Token(char k) : kind(k), value(0) {} 
	Token(char k, double val) : kind(k), value(val) {}    // we still need a "kind" to represent a number
};

Token get_token()
{
	char ch;
	std::cin >> ch; // read a character from the input
	switch (ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case 'e': // 'e' for escape
		return Token(ch); // return a token for the operator

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		std::cin.putback(ch); // put the digit back into the input stream
		double val;
		std::cin >> val; // read the full number
		return Token('8', val); // return a token for the number
	default:
		std::cerr << "Error: Invalid token!" << '\n';
		return Token('?'); // return an invalid token
	}
}

std::vector<Token> tokens;  // store tokens for the expression

int main()
{
	std::cout << "Enter an expression (e.g., 3 + 4): ";

	// Read tokens into the vector until the end of input
	while (std::cin)
	{
		Token t = get_token(); // Get the next token
		if (t.kind == 'e') // 'e' for escape
			break;

		switch (t.kind)
		{
		case '+':
			tokens.push_back(t);
			break;
		case '-':
			tokens.push_back(t);
			break;
		case '*':
			tokens.push_back(t);
			break;
		case '/':
			tokens.push_back(t);
			break;
		case '=':
			tokens.push_back(t);
			break;
		case '8': // number
			tokens.push_back(t);
			break;
		}
	}

	/* Just a few snags - programming the calculator this way means we have to find a '*' or '/'
	   do a sub-calculation, and then calculate '+' and '-' afterwards. */

	for (const auto& t : tokens)
	{
		
	}
}