/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3



Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

/*
class Solution{
public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size) {
        
        unordered_map<int, int> m;
        for(int i=0; i<size; i++) m[a[i]]++;
      
        for(auto it : m) {
            if(it.second > size/2) return it.first;
        }
        return -1;
    }
};

Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends