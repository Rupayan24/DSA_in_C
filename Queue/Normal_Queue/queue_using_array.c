#include<stdio.h>
#include<stdlib.h>

int f = -1;
int r = -1;

void enqueue(int x, int arr[], int n)
{
  if(r == n - 1)
  {
    printf("\nOverflow\n");
  }

  else if(f == -1 && r == -1)
  {
    f = r = 0;
    arr[r] = x;
  }

  else
  {
    r++;
    arr[r] = x;
  }
}

void dequeue(int arr[], int n)
{
  if(f == -1)
  {
    printf("\nUnderflow\n");
  }

  else if(f == 0 && r == 0)
  {
    f = r = -1;
  }

  else
  {
    printf("\n%d is popped out\n", arr[f]);
    f = f + 1;
  }
}

void front(int arr[], int n)
{
  if(f == -1 && r == -1)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    printf("\n %d is the front element\n", arr[f]);
  }
}

void display(int arr[], int n)
{
  if(f == -1 && r == -1)
  {
    printf("\nUnderflow\n");
  }

  else
  {
    for (int i = f; i <= r; i++)
    {
      printf(" %d ", arr[i]);
    }

    printf("\n");
  }
}

int main()
{
  int n;
  printf("\nEnter value of n : \n");
  scanf(" %d", &n);

  int arr[n];

  enqueue(3, arr, n);
  enqueue(4, arr, n);
  enqueue(5, arr, n);

  display(arr, n);
  dequeue(arr, n);
  display(arr, n);
  front(arr, n);
}