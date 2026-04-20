#include<stdio.h>

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void selection_sort(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int smallest = i;
    for (int j = i + 1; j < n; j++)
    {
      if(arr[j] < arr[smallest])
      {
        smallest = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
  }
}


int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  print(arr, n);
  selection_sort(arr, n);
  print(arr, n);

  return 0;
}