// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution {
public:	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    vector <int> res;
	    int carry = 0, i = a.size()-1, j = b.size()-1;
	    while(i>=0 || j>=0) {
	        int sum = 0;
	        if(i >= 0) sum += a[i--];
	        if(j >= 0) sum += b[j--];
	        sum += carry;
	        res.push_back(sum%10);
	        carry = sum/10;
	    }
	    if(carry) res.push_back(carry);
	    reverse(res.begin(), res.end());
	    return res;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends