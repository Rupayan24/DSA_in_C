#include <stdio.h>
#include <stdlib.h>

// TC - O(n ^ 2)
// SC - O(max_deadline)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int n, char id[], int profit[], int deadline[])
{

    int i;
    int j;
    for(i = 0; i < n; i++)
    {

        for(j = 0; j < n - i - 1; j++)
        {

            if(profit[j] < profit[j+1])
            {
                swap(&profit[j], &profit[j+1]);
                swap(&deadline[j], &deadline[j+1]);


                // swap ids here as they are char
                char temp = id[j];
                id[j] = id[j+1];
                id[j+1] = temp;
            }
        }
    }
}


void job_sequencing(int n, char id[], int profit[], int deadline[])
{

    sort(n, id, profit, deadline);

    int max_deadline = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(deadline[i] > max_deadline)
        {

            max_deadline = deadline[i];
        }
    }

    int total = 0;
    char slot[max_deadline];

    int j;
    for(j = 0; j < max_deadline; j++)
    {

        slot[j] = '@';
    }


    int k;
    for(k = 0; k < n; k++)
    {

        int x;
        for(x = deadline[k] - 1; x >= 0; x--)
        {

            if(slot[x] == '@')
            {

                slot[x] = id[k];
                total += profit[k];
                break;
            }
        }
    }


    int l;
    for(l = 0; l < max_deadline; l++)
    {

        if(slot[l] != '@')
        {
            printf(" %c", slot[l]);
        }
    }

    printf("\n");


    printf("Total Profit is : %d ", total);

}

int main()
{
    int n;
    printf("\nEnter number of jobs : \n");
    scanf("%d", &n);

    printf("\nStart entering details of each job : \n");

    char id[n];
    int profit[n];
    int deadline[n];

    int i;
    for(i = 0; i < n; i++)
    {

        printf("\nEnter Job Id : \n");
        scanf(" %c", &id[i]);

        printf("\nEnter profit : \n");
        scanf("%d", &profit[i]);

        printf("\nEnter deadline : \n");
        scanf("%d", &deadline[i]);
    }


    job_sequencing(n, id, profit, deadline);
    return 0;
}
