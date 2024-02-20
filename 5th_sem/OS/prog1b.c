// CPU Scheduling: SJF

#include <stdio.h>

int main(void)
{
    int p[10], bur[10], start[10], finish[10], tat[10], wt[10];
    int i, j, n, totwt=0, tottat=0;

    // Enter input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i+1;
        printf("Enter process burst time: ");
        scanf("%d", &bur[i]);
    }

    // SJF
    // first sort the processes according to their burst time using bubble sort
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(bur[i] > bur[j])
            {
                int temp = bur[i];
                bur[i] = bur[j];
                bur[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
    // calculate the waiting time and turnaround time for each process
    wt[0] = 0;
    tat[0] = bur[0];
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bur[i-1]; totwt += wt[i];
        tat[i] = tat[i-1] + bur[i]; tottat += tat[i];
    }


    // print the final result
    printf("\nPname\tBurTime\twaitTime\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", p[i], bur[i], wt[i], tat[i]);
        
    printf("Average waiting time: %.2f\n", (float)totwt/n);
    printf("Average Turnaround time: %.2f\n", (float)tottat/n);
}

// Output:  
// Enter the number of processes: 3
// Enter process burst time: 3
// Enter process burst time: 2
// Enter process burst time: 1

// Pname	BurTime	waitTime	TAT
// 3	1	0	1
// 2	2	1	3
// 1	3	3	6
// Average waiting time: 1.33
// Average Turnaround time: 3.33
