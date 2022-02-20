/*

Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals that 
cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].


Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping

*/

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto i : intervals) {
            if (merged.empty() || merged.back()[1] < i[0]) {
                merged.push_back(i);
            }
            
            else {
                merged.back()[1] = max(merged.back()[1], i[1]);
            }
        }
        return merged;
    }
};
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        int first = arr[0][0];
        int last = arr[0][1];
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i][0] <= last) {
                last = max(last, arr[i][1]);
            }
            else {
                v.push_back({first, last});
                first = arr[i][0];
                last = arr[i][1];
            }
        }
        v.push_back({first, last});
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends