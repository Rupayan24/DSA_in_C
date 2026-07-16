#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


void dfs(int vertex, int n, int graph[][n], bool visited[])
{
    int l;
    printf("%d ", vertex);


    for(l = 0; l < n; l++)
    {
        if(graph[vertex][l] == 1 && visited[l] == false)
        {
            visited[l] = true;
            dfs(l, n, graph, visited);
        }
    }
}

int main()
{
    int n;
    printf("\nEnter number of vertices : \n");
    scanf("%d", &n);


    int graph[n][n];
    printf("\nEnter the djacency matrix : \n");
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }


    bool visited[n];

    int k;
    for(k = 0; k < n; k++)
    {
        visited[k] = false;
    }

    visited[0] = true;


    printf("\nTraversal : \n");
    dfs(0, n, graph, visited);
    return 0;
}