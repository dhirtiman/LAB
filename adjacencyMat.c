// 23. Write a program to represent a Graph using adjacency matrix.

#include <stdio.h>

int main()
{
    int n, e, i, j, u, v, adj[20][20];

    printf("Enter number of vertices");
    scanf("%d", &n);

    printf("\nEnter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }


    printf("Enter edges (vertex 1 vertex2):\n");
    for(i=0;i<e;i++){
        scanf("%d %d",&u,&v);

        adj[u][v] = 1; // for directed graph
        adj[v][u] = 1; // Remove this line if graph is directed
    }

    printf("\nAdjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
Enter number of vertices5

Enter number of edges: 5
Enter edges (vertex 1 vertex2):
0 1
0 2
1 3
2 3
2 4

Adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 0
0 0 1 0 0
*/