// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template in C++

class Solution {
public:
    bool is_valid(int A[],int M,int mid,int N) {
        int student = 1;
        int sum = 0;
        for(int i=0; i<N; i++) {
            sum += A[i];
            if(sum > mid) {
                student++;
                sum = A[i];
            }
            if(student > M)
                return false;
        }
        return true;
    }
    
public:
    int findPages(int A[], int N, int M) {
        int high = 0;
        int low = 0;
        int ans = -1;
        for(int i=0; i<N; i++) {
            low = max(low, A[i]);
            high += A[i];
        }
        while(high >= low) {
            int mid = high + low >> 1;
            
            if(is_valid(A,M,mid,N)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends