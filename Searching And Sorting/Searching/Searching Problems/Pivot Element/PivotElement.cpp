//pivot element is minimum number of element present in array {3, 8, 10, 17, 1, 2, 3}  --> arr[4] = 1
//till maximum element array is in ascending order and then it is in desending order.

#include<bits/stdc++.h>
using namespace std;

int pivotElement(int arr[], int n) {
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

int main() {

    int arr[7] = {3, 8, 10, 17, 1, 2, 3};
    int result = pivotElement(arr, 7);
    cout << result << endl;
    
    return 0;
}

// TC is O(log N)