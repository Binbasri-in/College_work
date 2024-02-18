// LINKED FILE ALLOCATION

#include <stdio.h>
#include <conio.h>

struct file
{
    char fname[10];
    int start, size, block[10];
} f[10];

main()
{
    int i, j, n;
    clrscr();
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter file name:");
        scanf("%s", &f[i].fname);
        printf("Enter starting block:");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter no.of blocks:");
        scanf("%d", &f[i].size);
        printf("Enter block numbers:");
        for (j = 1; j <= f[i].size; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("File\tstart\tsize\tblock\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 1; j <= f[i].size - 1; j++)
            printf("%d--->", f[i].block[j]);
        printf("%d", f[i].block[j]);
        printf("\n");
    }
    getch();
}

// Output:
// Enter no. of files: 3
// Enter file name: file1
// Enter starting block: 1
// Enter no.of blocks: 3
// Enter block numbers: 1 2 3
// Enter file name: file2
// Enter starting block: 4
// Enter no.of blocks: 2
// Enter block numbers: 4 5
// Enter file name: file3
// Enter starting block: 6
// Enter no.of blocks: 1
// Enter block numbers: 6
// File	start	size	block
// file1	1	3	1--->2--->3
// file2	4	2	4--->5
// file3	6	1	6