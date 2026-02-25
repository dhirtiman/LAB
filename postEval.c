// Post fix evaulation

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot push.");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Cannot pop.");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char exp[200], *token;
    int operand1, operand2, result;

    printf("Enter the Postfix Expression(space separated):\n");
    fgets(exp, sizeof(exp), stdin);
    token = strtok(exp, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            operand2 = pop();
            operand1 = pop();
            switch (token[0])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                printf("Invalid Operator\n");
                return 1;
            }
            push(result);
        }
        token = strtok(NULL, " ");
    }

    printf("Result=%d\n", pop());
    return 0;
}


/*
Enter the Postfix Expression(space separated):
10 20 +
Result=30

*/