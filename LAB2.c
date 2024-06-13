#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#define MAXSIZE 30
#include <stdlib.h>
int s[MAXSIZE];
int top = -1;
int isdig(char);
void push(int);
int pop();
int op(int, int, char);
int main()
{
    char symbol, postfix[30];
    int a, b, res, i;
    // clrscr();

    printf("Postfix expression\n");
    scanf("%s", postfix);
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (isdig(symbol))
            push(symbol - '0');
        else
        {
            a = pop();
            b = pop();
            res = op(b, a, symbol);
            push(res);
        }
    }
    printf("The result of the expression is = ");
    printf("%d\n", pop());
    getch();
    return 0;
}
int pop()
{
    if (top != -1)
        return s[top--];
    else
    {
        printf("Stack underflow\n");
        return 0;
    }
}
void push(int item)
{
    if (top != MAXSIZE - 1)
        s[++top] = item;
    else
        printf("\nStak Overflow\n");
}
int op(int op1, int op2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
    return 0;
}
int isdig(char symbol1)
{
    return (symbol1 >= '0' && symbol1 <= '9');
}

/*
This C program evaluates a postfix expression. Here's how it works:

* It defines a stack using an integer array s.
* It defines functions push() and pop() to implement stack operations.
* It defines a function op() to perform arithmetic operations based on the operator.
* It defines a function isdig() to check if a character is a digit.

* In the main() function:
    It reads a postfix expression from the user.
    It iterates through each character of the postfix expression.

# If the character is a digit, it converts it to an integer and pushes it onto the stack.

# If the character is an operator, it pops two operands from the stack, performs the operation,
    and pushes the result back onto the stack.

* Finally, it prints the result of the expression.

Here's a brief explanation of the functions:

* push(int item): Pushes an item onto the stack.
* pop(): Pops an item from the stack.
* op(int op1, int op2, char symbol): Performs an arithmetic operation (+, -, *, /) on two operands.
* isdig(char symbol1): Checks if a character represents a digit.

This program assumes that the postfix expression is correctly formatted and does not handle cases like division
by zero or invalid postfix expressions. Additionally, it doesn't handle negative numbers or multi-digit numbers.

*/