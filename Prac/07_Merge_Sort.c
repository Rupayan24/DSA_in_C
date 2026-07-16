#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void merge(int arr[], int low, int mid, int high)
{
    int size = high - low + 1;
    int temp[size];


    int i = low;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }


    int x;
    int y;
    for(x = 0, y = low; x < size; x++)
    {
        arr[y] = temp[x];
        y++;
    }
}


void merge_sort(int arr[], int low, int high)
{
    if(low >= high)
    {

        return;
    }


    int mid = low + (high - low) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int n;
    printf("\nEnter number of elements in array : \n");
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


    merge_sort(arr, 0, n-1);

    int k;
    printf("\nSorted Array : \n");
    for(k = 0; k < n; k++)
    {

        printf("%d ", arr[k]);
    }
    return 0;
}