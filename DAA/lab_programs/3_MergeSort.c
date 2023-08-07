#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left[], int right[], int ls, int rs) {
    int i = 0, j = 0, k = 0;
    
    while (i < ls && j < rs) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    
    while (i < ls) {
        arr[k++] = left[i++];
    }
    
    while (j < rs) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int s) {
    if (s <= 1) return;
    
    int mid = s / 2;
    int left[mid];
    int right[s - mid];
    
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < s; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, s - mid);
    
    merge(arr, left, right, mid, s - mid);
}

int main() {
    //input array size
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 21000;
    }

    clock_t start, end;
    double cpu_time;
    
    start = clock();
    mergeSort(arr, n);
    end = clock();
    
    cpu_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000000.0; // in nano seconds

    printf("CPU_Time: %lf\n", cpu_time);
        
    return 0;
}
