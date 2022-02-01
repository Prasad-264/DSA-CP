#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start < end) {

        int mid = start+(end-start)/2;

        if(arr[mid] >= arr[0]) {
            start = mid + 1;
        }

        else {
            end = mid;
        }
    }
    return start;
}

int binarySearch(int arr[], int start, int end, int key) {
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			start = mid + 1;

		else
			end = mid - 1;
	}
	return -1;
}

int findPosition(int arr[], int n, int k) {
    int pivot = getPivot(arr, n);
    if(k >= arr[pivot] && k <= arr[n-1]) {
        return binarySearch(arr, pivot, n-1, k);
    }
    else {
        return binarySearch(arr, 0, pivot-1, k);
    }
}

int main() {

    int arr[7] = {3, 8, 10, 17, 1, 2, 3};
    int result = findPosition(arr, 7, 2);
    cout << result << endl;
    
    return 0;
}

// TC is O(log N)