#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int n)
{
    int i = low - 1;
    int j = low;

    for(j = low; j < high; j++)
    {
        if(arr[j] <= arr[high])
        {

            i++;
            swap(&arr[i], &arr[j]);
        }
    }


    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

void quick_sort(int arr[], int low, int high, int n)
{
    if(low >= high)
    {
        return;
    }


    int pivot = partition(arr, low, high, n);
    quick_sort(arr, low, pivot-1, n);
    quick_sort(arr, pivot+1, high, n);
}

int main()
{
    int n;
    printf("\nEnter numbr of elements : \n");
    scanf("%d", &n);

    int arr[n];
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nEnter element : \n");
        scanf("%d", &arr[i]);
    }

    int j;
    printf("\nOriginal Array : \n");
    for(j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }

    quick_sort(arr, 0, n-1, n);
    printf("\nSorted Array : \n");
    int k;
    for(k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }

    return 0;
}
