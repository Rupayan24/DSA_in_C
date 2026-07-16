#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 999999

void prims(int V, int graph[][V])
{
   int parent[V];
   int key[V];
   bool mstSet[V];

   // step 1
   int i;
   for(i = 0; i < V; i++)
   {
       key[i] = INF;
       mstSet[i] = false;
   }

   key[0] = 0;
   parent[0] = -1; // As the first vertex will never have a parent


   // Step 2
   int count;

   for(count = 0; count < V-1; count++)
   {
       int min = INF;
       int u;

       // step 3
       int a;
       for(a = 0; a < V; a++)
       {
           if(mstSet[a] == false && key[a] < min)
           {
               min = key[a];
               u = a;
           }
       }

       mstSet[u] = true;

       // step 4
       int b;
       for(b = 0; b < V; b++)
       {
           if(graph[u][b] && mstSet[b] == false && graph[u][b] < key[b])
           {
               key[b] = graph[u][b];
               parent[b] = u;
           }
       }

   }


   // step 5
   int c;
   for(c = 1; c < V; c++)
   {
       printf(" ");
       printf("%d-%d \t Weight : %d\n ", parent[c], c, graph[c][parent[c]]);
   }
}

int main()
{
    int V;
    printf("\nEnter number of vertices : \n");
    scanf("%d", &V);

    int graph[V][V];

    printf("\nEnter elements : \n");

    int i, j;
    for(i = 0; i < V; i++)
    {

        for(j = 0; j < V; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    prims(V, graph);
    return 0;
}
