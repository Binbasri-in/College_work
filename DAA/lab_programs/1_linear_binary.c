#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_search(int key, int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (key == a[i]) {
            printf("Successful search\n");
            printf("Element found at position %d\n", i+1);
            return;
        }
    }
    printf("Unsuccessful search\n");
}

void binary_search(int key, int a[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == a[mid]) {
            printf("Successful search\n");
            printf("Element found at position %d\n", mid+1);
            return;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Unsuccessful search\n");
}

void bubble_sort(int a[], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Generating random array elements...\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 5000;
    }

    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    int key;
    printf("Enter the key element: ");
    scanf("%d", &key);

    int choice;
    for (;;) {
        printf("1. Linear search\n2. Binary search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        clock_t start, end;
        double cpu_time_used;

        switch (choice) {
            case 1:
                start = clock();
                linear_search(key, a, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("CPU time: %f seconds\n", cpu_time_used);
                break;
            case 2:
                bubble_sort(a, n);
                start = clock();
                binary_search(key, a, n);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("CPU time: %f seconds\n", cpu_time_used);
                break;
        }
    } 

    return 0;
}
