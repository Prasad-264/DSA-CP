// if array {2, 3, 3, ,3 ,3 , 3, 7} is given print position of first and last of 3 -> 1 and 5

#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end) {

        int mid = start + (end-start)/2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end) {

        int mid = start + (end-start)/2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {

    int even[8] = {1, 2, 3, 3 , 3, 3, 4, 5};
    int first = firstOcc(even, 8, 3);
    int last = lastOcc(even, 8, 3);

    cout << first <<" " << last << endl;
    
    return 0;
}