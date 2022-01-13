#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
public:
    void helper(int arr[], vector<int>&v, int i, int &j, int n) {
        if(i==n/2-1) {
            j=n/2;
            return ;
        }
        
        i++;
        v.push_back(arr[i]);
        helper(arr,v,i,j,n);
        v.push_back(arr[j]);
        j++;
    }
	
public:
	void shuffleArray(int arr[],int n) {
        int j=1;
        vector<int>v;
        helper(arr,v,0,j,n);
        int i=0;
        while(i < v.size()) { 
            arr[((2*i)+2)%(n-1)]=v[i];
            i++;
        }
	}
};

// { Driver Code Starts.


int main() {
   	int t;
    cin >> t;
    while (t--) {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++) cin>>a[i];
	    
        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends