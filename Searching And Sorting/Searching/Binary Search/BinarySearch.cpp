// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

//  C++ Code for finding element x in given array :)
int binarySearch(int arr[], int start, int end, int x) {
	while (start <= end) {
		// Find middle element of the array by dividing 2
		int mid = (start + end) >> 1;

		// Check if x is present at mid
		if (arr[mid] == x)
			return mid;

		// If x greater check in right side
		if (arr[mid] < x)
			start = mid + 1;

		// If x is smaller check in left side
		else
			end = mid - 1;
	}
	// if we reach here, then element was not present
	return -1;
}
// Time Complexity is O(log N) 

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
