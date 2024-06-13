#include <stdio.h>
#include <ctype.h>
#include <conio.h>

#define SIZE 50

char stack[SIZE];
int top = -1; /* Global declarations */

void push(char elem)
{ /* Function for PUSH operation */
    stack[++top] = elem;
}

char pop()
{ /* Function for POP operation */
    return (stack[top--]);
}

int pr(char symbol)
{ /* Function for precedence */

    if (symbol == '^') /* exponent operator, highest precedence*/
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-') /* lowest precedence */
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
/* Main Program */
void main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    //    clrscr();
    printf("Enter Infix Expression : ");
    scanf("%s", infix);
    push('#');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop(); /* Remove ( */
        }
        else
        { /* Operator */
            while (pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (stack[top] != '#') /* Pop from stack till empty */
        postfix[k++] = pop();
    postfix[k] = '\0'; /* Make postfix as valid string */
    printf("\nPostfix Expression =  %s\n", postfix);
    getch();
}

/*
This C program converts an infix expression to a postfix expression. Here's how it works:

* It defines a stack to hold operators.
* It defines a function push() to push elements onto the stack.
* It defines a function pop() to pop elements from the stack.
* It defines a function pr() to determine the precedence of operators.
* It defines the main() function where the actual conversion from infix to postfix happens.
* It reads an infix expression from the user.
* It initializes the stack with # to mark the bottom of the stack.
* It iterates over each character of the infix expression:

* If the character is an opening parenthesis, it's pushed onto the stack.

* If the character is an operand (a letter or a digit), it's added directly to the postfix expression.

* If the character is a closing parenthesis, it pops operators from the stack and adds them to
the postfix expression until an opening parenthesis is encountered.

* If the character is an operator, it compares its precedence with the precedence of the operator
at the top of the stack. If the precedence of the current operator is lower,
it pops the operators from the stack and adds them to the postfix expression.

* After processing all characters, it pops remaining operators from the stack and adds them to the postfix expression.

* Finally, it prints the postfix expression.

Here's the explanation of the functions used:

push(): Pushes an element onto the stack.
pop(): Pops an element from the stack.
pr(): Determines the precedence of operators.
Overall, this program implements the Shunting Yard algorithm to convert infix expressions to postfix expressions. However, it uses a fixed-size stack (stack[SIZE]) which may cause issues if the expression exceeds the defined size. Additionally,
the program doesn't handle invalid expressions or errors.
*/