//peak element is maximum number of element present in array {2, 3, 4, 5, 3, 2}  --> arr[3] = 5
//till maximum element array is in ascending order and then it is in desending order.

#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start < end) {
        int mid = start+(end-start)/2;

        if(arr[mid] < arr[mid+1]) {
            start = mid + 1;
        }

        else {
            end = mid;
        }
    }
    return start;
}

int main() {

    int arr[6] = {3, 4, 5, 6, 3, 2};
    int result = peakElement(arr, 6);
    cout << result << endl;
    
    return 0;
}