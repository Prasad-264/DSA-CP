/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.


Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1

*/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        else {
            return a[1] > b[1];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // - Sort the intervals in increasing order of starting point
        // - If starting points are same, in decreasing order of ending point
        sort(intervals.begin(), intervals.end(), comp);
        
        int res = 0, right = -1;
        
        for(const vector<int>& v : intervals){
            if(v[1] > right){
                //in this case v[1] > right and v[0] > left
                ++res;
                right = v[1];
            }
            /*
            ignore these cases:
            1. v[0]==left && v[1]<=right:
            these intervals are covered by last interval
            2. v[0]>left && v[1]<=right:
            these intervals are covered by last interval
            */
        }
        
        return res;
    }
};

// TC : O(N log N)