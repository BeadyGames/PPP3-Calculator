# PPP3 Calculator

A console-based expression calculator written in C++ as a parser/tokenization exercise inspired by Chapter 5 of *Programming: Principles and Practice Using C++* by Bjarne Stroustrup.

The project implements a small recursive descent parser that evaluates arithmetic expressions using tokens, operator precedence, parentheses, unary operators, and basic error recovery.

## Features

- Addition, subtraction, multiplication, and division
- Parentheses for grouping expressions
- Operator precedence handling
- Input recovery after invalid expressions

## Example Usage

```text
2 + 3 =
Result: 5

2 + 3 * 4 =
Result: 14

(2 + 3) * 4 =
Result: 20

-5 + 2 =
Result: -3

q ```

## Project Structure

```text
main.cpp          Program entry point
calculator.cpp    Parser and calculation loop
calculator.h      Parser function declarations
token.cpp         Token stream implementation
token.h           Token and Token_stream definitions
log.cpp           Error helper
log.h             Error helper declaration ```

## Building

```text
## Visual Studio

Open Calculator.slnx or Calculator.vcxproj in Visual Studio 2026 and build the project.

## Command Line

If using a compiler such as `g++`

`g++ -std=c++20 -Wall -Wextra -pedantic main.cpp calculator.cpp token.cpp log.cpp -o calculator`

Then run,

`./calculator` or `calculator.exe` (Depending on OS) ```


