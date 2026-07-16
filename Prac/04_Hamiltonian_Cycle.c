#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



// TC - O(N!)
// SC - O(N)
bool isSafe(int v, int graph[][v], int path[], int pos, int i)
{
    // Connection with prev vertex
    if(graph[path[pos-1]][i] == 0)
    {
        return false;
    }

    // Duplicate checking
    int j;
    for(j = 0; j < pos; j++)
    {
        if(path[j] == i)
        {
            return false;
        }
    }

    return true;
}

int hamiltonian(int v, int graph[][v], int path[], int pos)
{
    // Base Case

    if(pos == v)
    {
        if(graph[path[pos-1]][0] == 1) // Edge to starting vertex present or not
        {
            return 1;
        }

        return 0;
    }




    int i;
    for(i= 1; i < v; i++)
    {
        if(isSafe(v, graph, path, pos, i))
        {
            path[pos] = i;
            if(hamiltonian(v, graph, path, pos + 1))
            {
                return 1;
            }
            path[pos] = -1;
        }
    }

    return 0;
}

int main()
{
    int v;
    printf("\nEnter number of vertices : \n");
    scanf("%d", &v);


    int graph[v][v];


    int i, j;

    printf("\nEnter adjacency matrix : \n");

    for(i = 0; i < v; i++)
    {

        for(j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }


    int path[v];

    int k;
    for(k = 0; k < v; k++)
    {

        path[k] = -1;
    }

    path[0] = 0;


    if(hamiltonian(v, graph, path, 1) == 1)
    {
        printf("\nHamiltonian Cycle found !\n");
        int l;
        for(l = 0; l < v; l++)
        {

            printf("%d->", path[l]);
        }

        printf("%d", path[0]);
    }

    else
    {

        printf("\nHamiltonian Cycle not found \n");
    }
    return 0;
}
