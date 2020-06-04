// Siddha Basu
// 6-4-20
// Quicksort algorithm using std::partition() in C++

#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int[], int);
void quickSort(int[], int*, int*);

int main()
{
    int[] arr = { 7, 5, 9, 12, 18, 10, 17, 15, 2, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, size);
    
    quickSort(arr, arr, arr + size)
    
    printArray(arr, size);

    return 0;
}

void quickSort(int arr[], int *begin, int *end)
{
    if (begin < end)
	{
        // using first element as pivot
		int *pivot = begin;

		// after partition, pivot will be placed at index 0, needs to be switched with swap
		pivot = partition(begin, end, [pivot](int x) { return x <= *pivot; }) - 1;
        
		swap(&arr[pivot - arr], &arr[begin - arr]);
        
        // simultaneously sort each partition of array
		quickSort(arr, begin, pivot);
		quickSort(arr, pivot + 1, end);
	}
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
