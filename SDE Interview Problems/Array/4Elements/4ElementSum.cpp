// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int arr[], int n, int target) {
    sort(arr, arr + n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            int new_target= target - arr[i] - arr[j];
            
            int start = j+1;
            int end = n-1;
             
            while(start < end) {
                int sum = arr[start] + arr[end];
                if (sum > new_target) end--;
                else if (sum  < new_target) start++;
                else return true; 
                
            }
        }
    }
    return false;
}