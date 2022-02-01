// Letter Combinations of a Phone Number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int ind, string ds, vector<string>& ans, string mapping[], string digits) {
        if(ind >= digits.length()) {
            ans.push_back(ds);
            return;
        }
        
        int number = digits[ind] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            ds.push_back(value[i]);
            solve(ind+1, ds, ans, mapping, digits);
            ds.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string ds = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, ds, ans, mapping, digits);
        return ans;       
    }
};

int main() {
    int t; cin >> t;
    while(t--) {
        string digits;
        cin >> digits;

        Solution os;
        vector<string> ans = os.letterCombinations(digits);

        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}