// return duplicate element... if n = 5 ->{1, 2, 3, 4, 3} so return 3. and n always present bwt 1 to n-1.

#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int> &arr,int n, int s) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == s) {
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, s; 
        cin >> n >> s;
        int arr;
        vector<int> v;
        for(int i=0; i<n; i++) {
            cin >> arr;
            v.push_back(arr);    
        }
        pairSum(v, n, s);
        
    } 
    return 0;
}