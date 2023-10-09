// program for floyd algorithm
#include<stdio.h>
#include<stdlib.h>

int a[10][10], n, i, j, k;

void floyd()
{
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]>(a[i][k]+a[k][j]))
                    a[i][j]=a[i][k]+a[k][j];
}

void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]==0 && i!=j)
                a[i][j]=999;
        }

    floyd();

    printf("The distance matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}