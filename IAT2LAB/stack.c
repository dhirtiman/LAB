#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

// Pop operation
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int main()
{
    int n, element, pops;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        push(element);
    }

    printf("Enter number of pop operations: ");
    scanf("%d", &pops);

    printf("Popped elements:\n");

    for (int i = 0; i < pops; i++)
    {
        int value = pop();
        if (value != -1)
            printf("%d ", value);
        else
            break;
    }

    printf("\n");

    return 0;
}