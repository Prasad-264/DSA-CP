#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;

        for(int j=i+1; j<n; j++) {

            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }

    // Printing sorted array
    for(int i=0; i<n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        selectionSort(arr, n);
    }
    
    return 0;
}