// knapsack dynamic programming
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int M, int wt[], int profit[], int n)
{
    int k[n+1][M+1];
    int i, w;
    for (i = 0; i <= n; i++)
    {
        for(w = 0; w <= M; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if(wt[i-1] <= w)
                k[i][w] = max(k[i-1][w], k[i-1][w-wt[i-1]] + profit[i-1]);
            else
                k[i][w] = k[i-1][w];
        }
    }
    return k[n][M];
}

int main()
{
    int i, n;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], profit[n];
    printf("Enter the weight and profit of each item:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &wt[i], &profit[i]);
    }
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int len = sizeof(profit)/sizeof(profit[0]);
    printf("The maximum profit is: %d\n", knapsack(capacity, wt, profit, len));
}