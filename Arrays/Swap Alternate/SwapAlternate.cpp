#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlt(int arr[], int size) {
    
    for(int i=0; i<size; i+=2) {
        if(i+1 < size) {
            swap(arr[i],arr[i+1]);
        }
    }        
}


int main() {
    int even[10] = {12, 11, 34, 56, 76, 43, 23, 98, 65, 33};
    swapAlt(even, 10);
    printArr(even, 10);

    return 0;
}