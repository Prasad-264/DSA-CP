// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns location of x in given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int start, int end, int key)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;

		// Check if x is present at mid
		if (arr[mid] == key)
			return mid;

		// If x greater, ignore left half
		if (arr[mid] < key)
			start = mid + 1;

		// If x is smaller, ignore right half
		else
			end = mid - 1;
	}

	// if we reach here, then element was not present
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int key = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, key);
	(result == -1) 
                ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}
