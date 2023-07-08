#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// merge function
void merge(int arr[], int left[], int right[], int ls, int rs)
{
    int i = 0, j = 0, k = 0;
    
    // merge left and right array
    while (i < ls && j < rs)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i]; i++;
        }
        else
        {
            arr[k] = right[j]; j++;
        }
        k++;
    }
    
    // copy remaining elements of left array if any
    while (i < ls)
    {
        arr[k] = left[i]; i++; k++;
    }
    
    // copy remaining elements of right array if any
    while (j < rs)
    {
        arr[k] = right[j]; j++; k++;
    }
}

// merge sort function
void mergeSort(int arr[], int s)
{
    int mid = s/2;
    int left[mid];
    int right[s-mid];
    int j = 0;
    int i;

    // base condition
    if (s <= 1) return;
    
    // divide array into two parts
    for (i = 0; i < mid; i++)
    {
        left[j] = arr[i]; j++;
    }
    for (i = mid; i < s; i++)
    {
        right[i-mid] = arr[i];
    }

    // recursive call for left and right array
    mergeSort(left, mid);
    mergeSort(right, s-mid);
    
    // merge left and right array
    merge(arr, left, right, mid, s-mid);
}

int main()
{
    int i;
    int n = 20000;
    int arr[n];

    // generate random numbers
    for (i = 0; i < n; i++)
        arr[i] = rand() % 21000;

    clock_t start, end;
    double cpu_time;
    
    // calculate time taken by merge sort
    start = clock();
    mergeSort(arr, n);
    end = clock();
    
    cpu_time = ((double)(end - start)/ CLOCKS_PER_SEC) * 1000000000; // in nano seconds

    printf("CPU_Time: %lf", cpu_time);
        
    return 0;
}