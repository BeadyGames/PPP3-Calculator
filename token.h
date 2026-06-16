#pragma once

const char number = '8'; // kind for numbers
const char quit = 'e'; // 'e' for "quit"
const char print = '='; // '=' for "print"

// Simple Token data structure
struct Token
{
	char kind;
	double value;

	Token(char k) : kind(k), value(0) {}    // Token that represents operators and parentheses
	Token(char k, double val) : kind(k), value(val) {}   // Token that represents numbers
};

// Manage the input stream and provide tokens
// Contains putback() to put a token back into the stream
class Token_stream
{
public:
	Token get();
	void putback(Token t);

private:
	Token buffer{ 0 };
	bool full{ false };
};