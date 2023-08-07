#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[], int first, int last) {
    if (first < last) {
        int pivot = first;
        int i = first + 1;
        int j = last;
        while (i <= j) {
            while (i <= last && a[i] <= a[pivot])
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
                swap(&a[i], &a[j]);
        }
        swap(&a[pivot], &a[j]);
        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++)
        a[i] = rand() % 5000;

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cpu_time_used *= 1.0e9;  // Convert to nanoseconds

    printf("Sorted array elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nCpu time: %.2f ns\n", cpu_time_used);

    return 0;
}
