#include<bits/stdc++.h>
using namespace std;

int maxPower(string s) {
    if(s.size() == 1) return 1;
    int currMax = 0;
    int maxLen = 0;
    
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1])
            currMax++;
        else
            currMax = 0;
        
        maxLen = max(maxLen, currMax+1);
    }
    
    return maxLen;    
    }

int main() {
    string s;
    cin >> s;
    int result = maxPower(s);
    cout << result << endl;
    
    return 0;
}

// TC is O(N)