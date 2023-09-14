#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20]={0}, p=0;
    int i, j, u;

    u = capacity;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u) break;

        x[i] = 1.0;
        p = p + profit[i];
        u = u - weight[i];
    }

    // add the remaining fractions in u if any
    if (i < n)
    {
        x[i] = u/weight[i];
        p = p + (x[i] * profit[i]);
    }

    printf("\n the result vector is: ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);
    printf("\n Max profit is: %f\n", p);
}

int main()
{
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    printf("\nEnter no. of objects: ");
    scanf("%d", &num);

    printf("Enter weights and profits:\n");
    for (i = 0; i < num; i++)
        scanf("%f %f", &weight[i], &profit[i]);

    printf("Enter the capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++)
        ratio[i] = profit[i]/weight[i];

    for (i = 0; i < num; i++)
        for (j = i+1; j < num; j++)
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
    
    knapsack(num, weight, profit, capacity);
}