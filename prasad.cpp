#include<bits/stdc++.h>
using namespace std;

/* C++ Function to return a minimum element in Array
   size of arr, n = 6 
   arr[] = {10, 20, 30, 70, 50, 40}
   output = 10
*/
int minInArray(int arr[], int n) { 
    // initial max is 10
    int min = arr[0];
    // Traverse array elements
    // from second and compare
    // every element with current min
    for(int i=1; i<n; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}
// Using C++ STL
int mini  = *min_element(arr, arr + n);
//                        ^      ^    
//                      start   end   

// Time Complexity of Both is O(N)

int main() {
    int n = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    int res = minInArray(arr, 6);
    cout << res <<" " ;
    return 0;
}
