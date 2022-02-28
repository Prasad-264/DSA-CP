/*
Given an array A[] of size N and a positive integer K, find the first negative integer
 for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:

Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 

*/

#define ll long long
vector<ll> printFirstNegativeInteger(ll int A[], ll int n, ll int k) {
    vector<ll> ans;
    queue<int> q;
    int i = 0, j = 0;
    while(j < n) {
        if(A[j] < 0) q.push(A[j]);
        if(j-i+1 < k) j++;
        else if(j-i+1 == k) {
            if(q.empty()) ans.push_back(0);
            else ans.push_back(q.front());
            if(A[i] == q.front()) q.pop();
            i++;
            j++;
        }
    }
    return ans;
 }