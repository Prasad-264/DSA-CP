#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {

    bool swapped = false;

    for (int i = 0; i < n-1; i++) {    
     
        // Last i elements are already in place
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
                swapped = true;
        }

        if(swapped == false)
            break ;       
    }
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

// TC is O(N*N)
// Best case time complexity is O(N)
// Worst case time complexity is O(N*N)