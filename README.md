# PPP3 Calculator

The Calculator program which Bjarne Stroustrup works through in Chapter 5; although, this is my attempt 
to see how far I could get without consulting the chapter for help. I have thoroughly enjoyed building this up from scratch
and it has been a very useful exercise.

## Snags

I have tried to see if I could create a vector to store operators - so when a user enters a `*` within a calculation, we can "look ahead" in order to evaluate expressions based on Mathematical laws. This becomes messy quite quickly. I can't see a way around the problem of finding a `*` or a `/` and evaluating the expression in Mathematical order other than writing a parser according to Mathematical laws and using tokens.

Using our `ignore()` function inside Token_stream, we initially looked for a `=` at the end of input to clear the `istream`. This idea worked until
I started given the program 'strange' input such as "This program is rubbish" or `2 * 3 + +`. The most effective solution was to use cin.clear() and cin.ignore().
  
