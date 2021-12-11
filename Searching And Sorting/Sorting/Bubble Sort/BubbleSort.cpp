#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (int j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
}
 
/* Function to print an array */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}