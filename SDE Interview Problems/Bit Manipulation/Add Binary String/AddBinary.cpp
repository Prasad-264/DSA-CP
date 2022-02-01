// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B) {
	    string s = "";
	    int i = A.length()-1, j = B.length()-1, carry = 0;
	    while(i>=0 || j>=0 || carry==1) {
	        carry += i >= 0 ? A[i--] - '0' : 0;
            carry += j >= 0 ? B[j--] - '0' : 0;
            s = char(carry % 2 + '0') + s;
            carry = carry >> 1;
	    }
	    return s;    
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends