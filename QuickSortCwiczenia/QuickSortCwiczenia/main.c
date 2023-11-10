#include <stdio.h>
#include <stdlib.h>

void printArray(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void middleOfThree(int* arr, int a, int b, int c, int* pivot, int* pivotNumber)
{
	if (arr[b] < arr[a] && arr[a] < arr[c] || arr[c] < arr[a] && arr[a] < arr[b])
	{
		*pivot = arr[a];
		*pivotNumber = a;
	}
	else if (arr[a] < arr[b] && arr[b] < arr[c] || arr[c] < arr[b] && arr[b] < arr[a])
	{
		*pivot = arr[b];
		*pivotNumber = b;
	}
	else
	{
		*pivot = arr[c];
		*pivotNumber = c;
	}
}

void returnPivot(int* arr, int low, int high, int* pivot, int* pivotNumber)
{
	if (high - low + 1 < 3)
	{
		*pivot = arr[high];
		*pivotNumber = high;
	}
	else
	{
		middleOfThree(arr, low, high, low + (high - low) / 2, pivot, pivotNumber);
	}
}

int partition(int* arr, int l, int r)
{
	int pivot; 
	int pivotNumber;
	returnPivot(arr, l, r, &pivot, &pivotNumber);
	swap(arr, pivotNumber, r);

	int s = l - 1;

	for (int i = l; i < r; i++)
	{
		if (arr[i] < pivot)
		{
			s++;
			swap(arr, i, s);
		}
	}

	swap(arr, s+1, r);
	return (s + 1);
}

void quickSort(int* arr, int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}
}

void sort(int* arr, int size)
{
	quickSort(arr, 0, size - 1);
}

int main(void)
{
	int arr[] = { 5, 8, 144, 77, 12, 55, 13, 34, 21, 89 };
	int size = sizeof(arr) / sizeof(*arr);

	sort(arr, size);

	printArray(arr, size);

	return 0;
}