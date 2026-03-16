// Write a program to add two polynomials using linked list representation.

// Program to perform Polynomial Addition using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    float co;
    int expo;
    struct node *link;
};

// Insert node at beginning
struct node *insert_begin(struct node *head, float co, int expo)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->co = co;
    newnode->expo = expo;
    newnode->link = head;

    return newnode;
}

// Add two polynomials
struct node *add(struct node *poly1, struct node *poly2)
{
    struct node *p1 = poly1;
    struct node *p2 = poly2;
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo == p2->expo)
        {
            result = insert_begin(result, p1->co + p2->co, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
        else if (p1->expo > p2->expo)
        {
            result = insert_begin(result, p1->co, p1->expo);
            p1 = p1->link;
        }
        else
        {
            result = insert_begin(result, p2->co, p2->expo);
            p2 = p2->link;
        }
    }

    // Remaining terms of first polynomial
    while (p1 != NULL)
    {
        result = insert_begin(result, p1->co, p1->expo);
        p1 = p1->link;
    }

    // Remaining terms of second polynomial
    while (p2 != NULL)
    {
        result = insert_begin(result, p2->co, p2->expo);
        p2 = p2->link;
    }

    return result;
}

// Create polynomial
struct node *create(struct node *head)
{
    int n, expo;
    float co;

    printf("Enter number of terms (ascending order of exponents): ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        printf("\nEnter coefficient of term %d: ", i);
        scanf("%f", &co);

        printf("Enter exponent of term %d: ", i);
        scanf("%d", &expo);

        head = insert_begin(head, co, expo);
    }

    printf("\n");
    return head;
}

int main()
{
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    struct node *sum = NULL;
    struct node *t;

    printf("\nFirst Polynomial\n");
    p1 = create(p1);

    printf("\nSecond Polynomial\n");
    p2 = create(p2);

    sum = add(p1, p2);

    printf("\nResult:\n");

    for (t = sum; t != NULL; t = t->link)
    {
        printf("%.1fx^%d", t->co, t->expo);

        if (t->link != NULL)
            printf(" + ");
    }

    printf("\n");

    return 0;
}

/*

First Polynomial
Enter number of terms (ascending order of exponents): 3

Enter coefficient of term 3: 10
Enter exponent of term 3: 0

Enter coefficient of term 2: 5
Enter exponent of term 2: 1

Enter coefficient of term 1: 6
Enter exponent of term 1: 2


Second Polynomial
Enter number of terms (ascending order of exponents): 3

Enter coefficient of term 3: 20
Enter exponent of term 3: 0

Enter coefficient of term 2: 5
Enter exponent of term 2: 1

Enter coefficient of term 1: 10
Enter exponent of term 1: 2


Result:
30.0x^0 + 10.0x^1 + 16.0x^2
*/