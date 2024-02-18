// CPU Scheduling: RR

#include <stdio.h>

int main(void)
{
    int bur[10] tat[10], wt[10], ct[10];
    int max, t, i, j, n, totwt=0, tottat=0, temp=0;

    // Enter input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter process burst time: ");
        scanf("%d", &bur[i]);
    }

    // Round Robin
    // Enter time slice
    printf("Enter time slice: ");
    scanf("%d", &t);

    // find the maximum burst time
    max = bur[0];
    for (i = 1; i < n; i++)
        if (max < bur[i])
            max = bur[i];
    
    // perform the round robin scheduling TODO
    // for (j = 0; j < (max/t)+1; j++)
    //     for (i = 0; i < n; i++)
    //         if (bur[i] <= t)
    //         {
    //             tat[i] = temp + bur[i];
    //             temp = temp + tat[i];
    //             bu[i] = 0;
    //         } else {
    //             bur[i] = bur[i] - t;
    //             temp = temp + t;
    //         }
             


    // print the final result
    printf("\nPname\tBurTime\twaitTime\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i], bur[i], wt[i], tat[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("Average waiting time: %.2f\n", (float)totwt/n);
    printf("Average Turnaround time: %.2f\n", (float)tottat/n);
}