#include<bits/stdc++.h>
using namespace std;
// ***** Kadanes Algorithm ******

/* C++ Function to return a Largest Sum Contiguous Subarray
   size of arr, n = 8
   arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}
   output = 7 bcoz sum of {4 + (-1) + (-2) + 1 + 5} = 7;
*/
int maxSubarraySum(int arr[], int n) { 
    // initial sum is 0
    int sum = 0;
    // initial maximum is negetive number
    int maxi = INT_MIN; 
    for(int i=0; i<n; i++) {

        // Adding array elements
        sum += arr[i];

        // update maxi with maximum of sum and maxi
        maxi = max(sum, maxi);

        // if the sum is less than 0, update sum to 0 
        if(sum < 0) sum = 0;
    }
    return maxi;
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
