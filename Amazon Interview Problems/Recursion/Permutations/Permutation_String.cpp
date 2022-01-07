#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void func(int ind, string& S, vector<string>& ans) {
        if(ind == S.length()){
            ans.push_back(S);
            return;
        }
        
        for(int i=ind; i<S.length(); i++) {
            swap(S[ind], S[i]);
            func(ind+1, S, ans);
            swap(S[ind], S[i]);
        }
    }
public:
    vector<string> find_permutation(string S) {
        vector<string> ans;
        //sort(S.begin(), S.end());
        func(0, S, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i : ans) {
	    	cout << i << " ";
	    }
	    cout << endl;
    }
	return 0;
}