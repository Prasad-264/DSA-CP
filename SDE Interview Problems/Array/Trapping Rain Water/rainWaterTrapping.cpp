// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

#define ll long long
class Solution {
public:
    long long trappingWater(int arr[], int n) {
        ll int l = 0, r = n-1, water = 0;
        ll int leftMax = 0, rightMax = 0;
        while(l<=r) {
            if(arr[l] <= arr[r]) {
                if(arr[l] >= leftMax) leftMax = arr[l];
                else water += (leftMax - arr[l]);
                l++;
            }
            else {
                if(arr[r] >= rightMax) rightMax = arr[r];
                else water += (rightMax - arr[r]);
                r--;
            }
        }
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends