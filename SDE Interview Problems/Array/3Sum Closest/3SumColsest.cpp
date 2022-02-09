// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int first = 0 ; first < nums.size()-2 ; ++first) {
            if(first > 0 && nums[first] == nums[first-1]) continue;
            int second = first+1;
            int third = nums.size()-1;            
            while(second < third) {
                int curSum = nums[first] + nums[second] + nums[third];
                if(curSum == target) return curSum;
                if(abs(target-curSum) < abs(target-closest)) {
                    closest = curSum;
                }
                if(abs(target-curSum) == abs(target-closest)) {
                    closest = max(curSum, closest);
                }
                if(curSum < target) {
                    second++;
                }
                else {
                    third--;
                }
            }
        }
        return closest;
        
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends