#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// TC - O(n!)
// SC - O(N)

void print(int v, int path[]) 
{
  for (int i = 0; i < v; i++)
  {
    printf("%d->", path[i]);
  }

  printf("\n-------\n");
}

bool isSafe(int v, int graph[v][v], int vertex, int path[], int pos)
{
  if(graph[path[pos-1]][vertex] == 0) // there is no edge between previous vertex and current vertex
  {
    return false;
  }

  for (int i = 0; i < pos; i++) // duplicate check for path
  {
    if(path[i] == vertex)
    {
      return false;
    }
  }

  return true;
}

void solve(int v, int graph[v][v], int path[], int pos)
{
  if(pos == v)
  {
    if(graph[path[pos-1]][path[0]] == 1)
    {
      print(v, path);
    }

    return;
  }

  for (int vertex = 1; vertex < v; vertex++)
  {
    if(isSafe(v, graph, vertex, path, pos))
    {
      path[pos] = vertex;
      solve(v, graph, path, pos + 1);
      path[pos] = -1; // backtrack
    }
  }
}

int main()
{
  int v;
  printf("Enter number of vertices : \n");
  scanf("%d", &v);

  int graph[v][v];

  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
  


  int path[v];
  path[0] = 0;

  for (int i = 1; i < v; i++)
  {
    path[i] = -1;
  }

  

  solve(v, graph, path, 1);

  return 0;
}