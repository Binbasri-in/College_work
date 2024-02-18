#include <stdio.h>
void main()
{
    int i, j, k, n, m = 0, flag[10], que[10], a[10][10];
    printf("Enter the number of elements :  ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        flag[i] = 0, que[i] = 0;
    printf("Enter the matrix elements : \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                flag[j]++;
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            if (!flag[i])
            {
                flag[i] = -1;
                que[++m] = i;

                for (j = 1; j <= n; ++j)
                {
                    if (a[i][j] && flag[j] > 0)
                    {

                        flag[j]--;
                    }
                }
            }
        }
    }
    if (m == n)
    {
        printf("toplojical order are \n");
        for (i = 1; i <= n; i++)
        {

            printf("%d ", que[i]);
        }
    }
    else
        printf("there is no toplojical order  \n");
}