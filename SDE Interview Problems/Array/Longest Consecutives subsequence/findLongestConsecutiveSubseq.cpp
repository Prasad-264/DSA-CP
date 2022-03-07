/*
Given an array of positive integers. Find the length of the longest sub-sequence such 
that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.


Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.
*/

//------------------------------------ sorting (Brute Force) O(N logN) ------------------------------------------
class Solution {
public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n) {
        sort(arr, arr+n);
        int ans = 1;
        int cnt = 1;
        for(int i = 1; i < n; ++i) {
            if(arr[i] - 1 == arr[i-1]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else if(arr[i]-1 != arr[i-1] && arr[i] != arr[i-1]) cnt = 1;
        }
        return ans;
    }
};

//-------------------------------- Using Set ---------------------------------
// Lineat time solution
class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        set<int> s(arr, arr+N);
        vector<int> v(s.begin(), s.end());

        int count = 1, res = 1;

       
        for(int i=1; i<v.size(); i++) {
           if(v[i] == v[i-1]+1) count++;
           else count = 1;
           res = max(res, count);
       }
       return res;
   }
};

//-------------------------------- Hashing -----------------------------------
class Solution {
public:
    int findLongestConseqSubseq(int arr[], int n) {
        map<int,int>m;   //making of the map
        //insertion of element in map sorted order
        for(int i=0; i<n; i++) m[arr[i]]++;
        
        int count = 1;
        int prev = m.begin()->first;
        int ans = INT_MIN;
        for(auto it=m.begin(); it!=m.end(); it++) {
            if((it->first)-prev == 1) {
                count++;
                prev = it->first; //upadating previous
            }
            else {
                prev=it->first;  //upadating previous
                count = 1; 
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
