// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution {   
public:
    bool isPalindrome(string& s) {
        int r = s.length()-1;
        int l = 0;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int n, string arr[]) {
        unordered_map<string, int> m;
        for(int i=0; i<n; i++) {
            auto s = arr[i];
            reverse(s.begin(), s.end());
            m.insert({s, i});
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<arr[i].size(); j++) {
                string s1 = arr[i].substr(0,j);
                string s2 = arr[i].substr(j);
                if(m.count(s1) && isPalindrome(s2) && m[s1]!=i) return true;
                if(m.count(s2) && isPalindrome(s1) && m[s2]!=i) return true;
            }
        }
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends