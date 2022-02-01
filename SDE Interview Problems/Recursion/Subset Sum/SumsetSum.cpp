#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& ds) {
        if(ind == N) {
            ds.push_back(sum);
            return;
        }
        // Pick element and add to Sum..!
        func(ind+1, sum + arr[ind], arr, N, ds);
        // Not pick element..!
        func(ind+1, sum, arr, N, ds);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ds;
        func(0, 0, arr, N, ds);
        //sort(ds.begin(), ds.end());
        return ds;
        
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}