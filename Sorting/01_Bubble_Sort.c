#include<stdio.h>

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}


void bubble_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int flag = 0;
    for (int j = 0; j < n - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }

    if(flag == 0) // no swaps for this pass, -> so sorting is already done -> no need to do any more sorting
    {
      break;
    }
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
  bubble_sort(arr, n);
  print(arr, n);
}