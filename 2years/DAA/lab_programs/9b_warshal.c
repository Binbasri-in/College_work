#include <stdio.h>

void warshall(int R[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
}

int main()
{
    int R[10][10], i, j, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &R[i][j]);
    warshall(R, n);
    printf("The transitive closure is: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", R[i][j]);
        printf("\n");
    }
    return 0;
}