// 8. Write a program to insert elements into a singly linked list and delete specified elements from the list.
// Display the list after each insertion and deletion operation.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function to display the list */
void display()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Function to insert at end */
void insert_at_end(int value)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    display();
}

/* Function to delete a given element */
void deleteElement(int value)
{
    struct node *temp = head, *prev = NULL;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->data == value) // if the element is at the begining
    {
        head = head->next;
        free(temp);
        display();
        return;
    }

    while (temp != NULL && temp->data != value) // XOR stuff , if either list ends or data is found the loop will break
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    display();
}

void main()
{
    int choice, value;

    // clrscr();

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert_at_end(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteElement(value);
            break;

        case 3:
            break;

        default:
            printf("Invalid choice");
        }
    } while (choice != 3);
}
/*

1. Insert
2. Delete
3. Exit
Enter your choice: 1
Enter value to insert: 1
List: 1 -> NULL

1. Insert
2. Delete
3. Exit
Enter your choice: 1
Enter value to insert: 2
List: 1 -> 2 -> NULL

1. Insert
2. Delete
3. Exit
Enter your choice: 1
Enter value to insert: 3
List: 1 -> 2 -> 3 -> NULL

1. Insert
2. Delete
3. Exit
Enter your choice: 2
Enter value to delete: 2
List: 1 -> 3 -> NULL

1. Insert
2. Delete
3. Exit
Enter your choice: 3
*/