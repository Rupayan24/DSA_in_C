#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int queue[20];
int front = 0;
int rear = 0;


// Empty

bool empty()
{

    if(front == rear)
    {
        return true; // empty
    }

    return false; // not empty
}

// Push
int push(int x)
{
    queue[rear] = x;
    rear++;
}

// Pop
void pop()
{

    front++;
}


// front_element
int front_element()
{
    return queue[front];
}



int main()
{
    int n;
    printf("\nEnter number of vertices : \n");
    scanf("%d", &n);


    int graph[n][n];

    printf("\nEnter the adjacency matrix of the graph : \n");
    int i, j;
    for(i = 0; i < n; i++)
    {

        for(j = 0; j < n; j++)
        {

            scanf("%d", &graph[i][j]);
        }
    }


    int visited[n];

    int k;
    for(k = 0; k < n; k++)
    {

        visited[k] = 0; // unvisisted
    }

    visited[0] = 1;
    push(0);

    printf("\nTraversal from 0 : \n");

    while(!empty())
    {
        int curr = front_element();

        printf("%d ", curr);
        pop();
        int l;
        for(l = 1; l < n; l++)
        {
            if(graph[curr][l] == 1 && visited[l] == 0)
            {
                visited[l] = 1;
                push(l);
            }
        }
    }


    return 0;
}
