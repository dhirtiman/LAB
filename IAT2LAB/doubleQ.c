// 16. Write a program to implement Double Ended Queue (Deque) using arrays.

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at Rear only
void insertRear(int value)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1)
    { // First element
        front = rear = 0;
    }

    rear = (rear + 1) % MAX;
    deque[rear] = value;
    printf("Inserted at Rear: %d\n", value);
}

// Delete from Front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted from Front: %d\n", deque[front]);

    if (front == rear)
    { // last element
        front = rear = -1;
    }
    front = (front + 1) % MAX
}

// Delete from Rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted from Rear: %d\n", deque[rear]);

    if (front == rear)
    { // last element
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

// Display
void display()
{
    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Input Restricted Deque ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            deleteRear();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}

/*
--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 1
Enter value: 10
Inserted at Rear: 10

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 1
Enter value: 20
Inserted at Rear: 20

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 1
Enter value: 30
Inserted at Rear: 30

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 4
Deque elements: 10 20 30

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 2
Deleted from Front: 10

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 4
Deque elements: 20 30

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 3
Deleted from Rear: 30
f
--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 4
Deque elements: 20

--- Input Restricted Deque ---
1. Insert at Rear
2. Delete from Front
3. Delete from Rear
4. Display
5. Exit
Enter your choice: 5
*/
