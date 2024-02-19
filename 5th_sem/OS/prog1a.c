// CPU Scheduling: FCFS

#include <stdio.h>

int main(void)
{
    int p[10], arr[10], bur[10], start[10], finish[10], tat[10], wt[10];
    int i, n, totwt=0, tottat=0;

    // Enter input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i+1;
        printf("Enter arrive time, and burst time: ");
        scanf("%d%d", &arr[i], &bur[i]);
    }

    // FCFS
    for(i = 0; i < n; i++)
    {
        start[i] = (i == 0) ? arr[i] : finish[i-1];
        wt[i] = start[i] - arr[i];
        finish[i] = start[i] + bur[i];
        tat[i] = finish[i] - arr[i];
    }

    // print the final result
    printf("\n Pname\tArrTime\tBurTime\tStartTime\tTAT\tFinishTime\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], arr[i], bur[i], start[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("Average waiting time: %.2f\n", (float)totwt/n);
    printf("Average Turnaround time: %.2f\n", (float)tottat/n);
}

// Output:
// Enter the number of processes: 3
// Enter arrive time, and burst time: 0 3
// Enter arrive time, and burst time: 1 2
// Enter arrive time, and burst time: 2 1

//  Pname	ArrTime	BurTime	StartTime	TAT	    FinishTime
//  1	    0	    3	    0	        3	    3
//  2	    1	    2	    3	        4	    5
//  3	    2	    1	    5	        4	    6
// Average waiting time: 2.33
// Average Turnaround time: 3.67
