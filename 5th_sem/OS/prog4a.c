// 4. Write a C - program to implement the file allocation technique.(Linked, Indexed or Contiguous)

// INDEXED FILE ALLOCATION

#include <stdio.h>
#include <conio.h>

main()
{
    int n, m[20], i, j, sb[20], s[20], b[20][20], x;
    clrscr();
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter starting block and size of file%d:", i + 1);
        scanf("%d%d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file%d:", i + 1);
        scanf("%d", &m[i]);
        printf("enter blocks of file%d:", i + 1);
        for (j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }
    printf("\nFile\t index\tlength\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
    }
    printf("\nEnter file name:");
    scanf("%d", &x);
    printf("file name is:%d\n", x);
    i = x - 1;
    printf("Index is:%d", sb[i]);
    printf("Block occupied are:");
    for (j = 0; j < m[i]; j++)
        printf("%3d", b[i][j]);
    getch();
}


// Output:
// Enter no. of files: 3
// Enter starting block and size of file1: 1 3
// Enter blocks occupied by file1: 3
// enter blocks of file1: 1 2 3
// Enter starting block and size of file2: 4 2
// Enter blocks occupied by file2: 2
// enter blocks of file2: 4 5
// Enter starting block and size of file3: 6 1
// Enter blocks occupied by file3: 1
// enter blocks of file3: 6
// File	 index	length
// 1	1	3
// 2	4	2
// 3	6	1
// Enter file name: 2
// file name is:2
// Index is:4Block occupied are: 4 5

