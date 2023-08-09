/*
Write C/C++ programs to perform Linear and Binary search of an element from a set of n
elements. Run the program for varied values of n> 5000 and record the time taken to sort. Plot a
graph of the time taken versus non graph sheet. The elements can be read from a file or can be

generated using the random number generator. Demonstrate using C/C++ how the divide-and-
conquer method works along with its time complexity analysis: worst case, average case and

best case. Compare the performance of both the algorithms.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start;
clock_t end;

void linear(int arr[],int key, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			printf("The key was found at position %d\n", i+1);
			return;
		}
	}
	printf("Not found!!!\n");
}

void binary(int arr[], int key, int n)
{
	int mid, l=0, h=n, cur;
	while (l <= h)
	{
		mid = (l+h)/2;
		cur = arr[mid];
		if (cur == key)
		{
			printf("The key was found at position %d\n", mid+1);
			return;
		}
		else if (key < cur)
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("Not found!!!\n");
}


int main()
{
	double cpu_time;
	int n, i, key, j, temp;

	printf("Enter size: ");
	scanf("%d", &n);
	int arr[n];

	for (i = 0; i < n; i++)
		arr[i] = rand() % 10000;

	// sort
	for (i = 1; i < n; i++)
		for (j = 0; j < n-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	
	printf("Enter key: ");
	scanf("%d", &key);

	start = clock();
	binary(arr, key, n);
	end = clock();

	cpu_time = ((double)(end - start)/CLOCKS_PER_SEC) * 1e9;

	printf("CPU Timr: %5.f\n", cpu_time);

}