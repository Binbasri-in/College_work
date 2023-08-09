/*
Write C/C++ programs to sort a given set of n integer elements using Quick Sort method and
compute its time Complexity. Run the program for varied values of n> 5000 and record the time
taken to sort. Plot a graph of the time taken versus non graph sheet. The elements can be read
from a file or can be generated using the random number generator. Demonstrate using C/C++
how the divide-and-conquer method works along with its time complexity analysis: worst case,
average case and best case.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick(int arr[], int l, int h)
{
	if (l < h)
	{
		int pivot = arr[l];
		int i = l+1, j = h;

		while (i <= j)
		{
			while (arr[i] <= pivot && i <= h) i++;
			while (arr[i] > pivot) j--;
			if (i<j) swap(&arr[i], &arr[j]);
		}
		swap(&arr[l], &arr[j]);

		quick(arr, l, j-1);
		quick(arr, j+1, h);
	}
}

int main() {
    clock_t start, end;
    double cpu_time;

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }


    start = clock();
    quick(arr, 0, n - 1);
    end = clock();

    cpu_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1e9;

    printf("CPU Time: %5.f nanoseconds\n", cpu_time);

    return 0;
}
