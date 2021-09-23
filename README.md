# Calculate Infix Notation Without Converting To Postfix

What is Infix, Prefix and Postix Notation?
<img src='https://youtu.be/t7YWDiz8LMY' title='Video Walkthrough' width='' alt='Video Walkthrough' />


This programs uses infix notation and calculates arithmatic operations but does this without converting to a postfix notation first.

The program was made possible with the stack class from the STL Library and uses conditional statements in different functions to output the correct result.

I tried to comment and make each and every step clear and understandable. I would recommend tracing from the main to the different functions if you are making something similar.

The requirements for this program are given below:

Write a program that uses stacks to evaluate an arithmetic expression in infix notation without converting to postfix.

Your program should take a numeric input such as 2+4*10 and output the correct result. 
Some of the requirements are:
A)  Operators are +, -, *, /
B)  Assume that the expression is formed correctly so that each operation has two arguments.
C)  The expression can have parenthesis, for example: 3*(4-2)+6 
D)  The expression can have negative numbers.
E)  The expression can have spaces in it, for example: 3  *  (4-2)  +6 

Here's some information that helped me write this program:

GENERAL STACK MEMBER FUNCTIONS FROM STL LIBRARY
empty: Test whether container is empty (public member function )
size: Return size (public member function )
top: Access next element (public member function )
push: Insert element (public member function )
emplace: Construct and insert element (public member function )
pop: Remove top element (public member function )
swap: Swap contents (public member function )

Order of Precedences:
1. parenthesis () {} []
2. Exponents (right to left)
3. Multiplication and division (left to right) 
4. Addition and Subtraction (left to right)
