#include <stdio.h>
#include <stdlib.h>
#define INF 9999

void floyd_warshall(int n, int graph[][n])
{
    int k, i, j;

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(graph[i][k] != INF && graph[k][j] != INF)
                {
                                    if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
                }
            }
        }
    }
}

void print(int n, int graph[][n])
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == INF)
            {
                printf("%7s", INF);
            }

            else
            {

                printf("%7d", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("\nEnter number of vertices : \n");
    scanf("%d", &n);


    int graph[n][n];

    printf("\nEnter adjacency matrix : \n");

    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {

            scanf("%d", &graph[i][j]);
        }
    }


    floyd_warshall(n, graph);


    printf("\nFinal Matrix : \n");
    print(n ,graph);
    return 0;
}
