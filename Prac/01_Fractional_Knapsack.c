#include <stdio.h>
#include <stdlib.h>

// TC - O(n^2)
// SC - O(1)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int profit[], int weight[], int n)
{
    int i;
    int j;
    for(i = 0; i < n; i++)
    {

        for(j = 0; j < n - i - 1; j++)
        {

            double ratio_1 = (double) profit[j] / weight[j];
            double ratio_2 = (double) profit[j+1] / weight[j+1];

            if(ratio_1 < ratio_2)
            {

                // Profit Swap
                swap(&profit[j], &profit[j+1]);

                // Weight Swap
                swap(&weight[j], &weight[j+1]);
            }
        }
    }
}

double fractional_knapsack(int w, int profit[], int weight[], int n)
{

    bubble_sort(profit, weight, n);


    int i;

    double total = 0;


    for(i = 0; i < n; i++)
    {

        if(weight[i] <= w)
        {

            total += profit[i];
            w -= weight[i];
        }

        else
        {

            total += ((double)profit[i] / weight[i]) * w;
            w = 0;
            break;
        }
    }

    return total;
}

int main()
{
    int n;
    printf("\nEnter Number of items : \n");
    scanf("%d", &n);

    int w;
    printf("\nEnter total capacity : \n");
    scanf("%d", &w);

    int profit[n];
    int weight[n];
    int i;
    for(i = 0; i < n; i++)
    {

        printf("\nEnter profit of item : \n");
        scanf("%d", &profit[i]);

        printf("\nEnter weight of item : \n");
        scanf("%d", &weight[i]);
    }

    double final_value = fractional_knapsack(w, profit, weight, n);
    printf("\nFinal Profit is : %f\n", final_value);
    return 0;
}