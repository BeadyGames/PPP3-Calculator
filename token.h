#pragma once

const char number = '8'; // kind for numbers
const char quit = 'e'; // 'e' for "quit"
const char print = '='; // '=' for "print"

// Simple Token data structure
// A Token contains a kind and value.
struct Token
{
	char kind;
	double value;

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