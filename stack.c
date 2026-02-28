// Implement stack operations in c

#include<stdio.h>
#include<conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if(top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot push.");
        return;
    }

    printf("\nEnter value to push: ");
    scanf("%d", &value);

    stack[++top] = value;
    printf("\n%d pushed successfully.", value);
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow! Cannot pop.");
        return;
    }
    printf("\nPopped element: %d", stack[top--]);
 }

void peek()
{
    if(top == -1)
    {
        printf("\nStack is empty.");
        return;
    }
    printf("\nTop element is: %d", stack[top]);
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("\nStack is empty.");
        return;
    }
    printf("\nStack elements are:\n");
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void main()
{
    int choice;

    do
    {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;

            case 5: printf("\nExiting...");
                    break;

            default: printf("\nInvalid choice!");
        }

    } while(choice != 5);

}