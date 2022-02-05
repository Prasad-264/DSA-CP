/*
Given two unsorted arrays A of size N and B of size M of distinct elements, 
the task is to find all pairs from both arrays whose sum is equal to X.

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.


*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x) {
        vector<pair<int, int>> sum;
        map<int,int>mp;
        for(int i=0; i<n; i++) {
            mp[a[i]]++;
        }
        for(int i=0; i<m; i++) {
            if(mp.find(x-b[i]) != mp.end()) {
                sum.push_back({x-b[i], b[i]});
            }
        }
        sort(sum.begin(), sum.end());
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}  // } Driver Code Ends