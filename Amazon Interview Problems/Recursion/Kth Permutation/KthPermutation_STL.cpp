#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
      string s = "";
      for(int i=1;i<=n;i++){
        s.push_back(i+'0');
      }
      while(k--){
        if(!k){
          return s;
        }
        next_permutation(s.begin(),s.end());
      }
      return s;
    }
};

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        Solution os;
        string ans = os.getPermutation(n, k);
        cout << ans << endl;
    }
    return 0;
}

// Naive Approch using C++ STL