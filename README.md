# Calculator
A Calculator written in C that can do handle inputs in both infix and postfix containing "+ - X / ^" operators.

postfix.h takes in an expression written in postfix notation and evaluates it using a stack by performing push and pop operations based on the case.

infix.h takes in an epression written in infix notation and evaluates it by converting it to a postfix expression and passing then evaluating it using postfix.h
