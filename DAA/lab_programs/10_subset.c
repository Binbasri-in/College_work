#include <stdio.h>

int isSubsetSum (int set[], int n, int target_sum, int selected[])
{
    if (target_sum == 0)
        return 1;

    if (n == 0)
        return 0;

    if (set[n - 1] > target_sum)
        return isSubsetSum(set, n - 1, target_sum, selected);

    if (isSubsetSum(set, n - 1, target_sum, selected))
        return 1;

    if (isSubsetSum(set, n - 1, target_sum - set[n - 1], selected))
    {
        selected[n - 1] = 1;
        return 1;
    }

    return 0;
}

int main()
{
    int n, i, target_sum, set[10], selected[10]={0};

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    if (isSubsetSum(set, n, target_sum, selected))
    {
        printf("The subset is: ");
        for (i = 0; i < n; i++)
            if (selected[i])
                printf("%d ", set[i]);
        printf("\n");
    }
    else
        printf("No subset with the given sum exists.\n");

}