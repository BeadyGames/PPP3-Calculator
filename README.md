# PP3 Calculator

The Calculator program which Bjarne Stroustrup works through in Chapter 5; although, this is my attempt 
to see how far I could get without consulting the chapter for help.

## Snags

I have tried to see if I could create a vector to store operators - so when a user enters a '*' within a calculation, we can can "look ahead" in order to evaluate expressions based on Mathematical laws. This becomes messy quite quickly. I can't see a way around the problem of finding a '*' or a '/' and evaluating the expression in Mathematical order other than Tokenizing and creating different functions to deal with order of operations.

## Mathematical Laws

- Number: Every number is a Term and Expression
- Term: Number OR Term '*' Number OR Term '/' Number
- Expression: Term OR Expression '+' Term OR Expression '-' Term

## Example

2 is a number. As 2 is a number, it's also a Term. As 2 is a Term, it's also an Expression. Is it followed by a '+' or '-'?
  
