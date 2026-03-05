// 19. // 20 Write a program to implement Breadth First Search (BFS)
// traversal of a graph.

#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear || front == -1;
}

void BFS(int adj[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int i, v;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty())
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int adj[MAX][MAX], n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}

/*
Enter number of vertices: 5
Enter adjacency matrix:

0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 0
0 0 1 0 0

Enter starting vertex: 0
BFS Traversal: 0 1 2 3 4
*/