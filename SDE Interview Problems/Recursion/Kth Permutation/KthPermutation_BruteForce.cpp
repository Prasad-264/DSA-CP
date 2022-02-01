#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string>temp;
public:
    string getPermutation(int n, int k) {
        string res="",initial="";
        // creating string 
        for(int i=1;i<=n;++i)
            initial+=to_string(i);  

        solve(res,initial);
        
        // sorting temp
        sort(temp.begin(),temp.end());
        
          // in 0 indexing return k-1 in temp to get Kth permutation
        return temp[k-1];
        
    }
    void solve(string res,string initial)
    {
        // base case
        if(initial.size()==0)
        {
            temp.push_back(res);
            return;
        }
        for(int i=0;i<initial.size();++i)
        {   
            res.push_back(initial[i]);
            solve(res,initial.substr(0,i)+initial.substr(i+1));
            res.pop_back();
        }
    }
};

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.getPermutation(n, k);
        cout << ans << endl;
    }
    return 0;
    
}