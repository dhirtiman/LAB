// 20. Write a program to implement
// Depth First Search (DFS) traversal of a graph.

#include <stdio.h>

int n;
int adj[20][20];
int visited[20];

void dfs(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    dfs(start);

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

DFS Traversal: 0 1 3 2 4

*/