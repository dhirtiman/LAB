// 15./// Write a program to implement a circular queue and perform insertion and deletion
// operations.

#include <stdio.h>
#define MAX 5

int cq[MAX], front = -1, rear = -1;

void enqueue() {
    int x;
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue Full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue: ");
    for ( i = front; i != (rear+1)%MAX ; i = (i+1)%MAX ) {
	 printf("%d ", cq[i]);
    }  
}

int main() {
    int ch;
    while (1) {
        printf("\n1.enqueue 2.dequeue 3.display 4.exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}