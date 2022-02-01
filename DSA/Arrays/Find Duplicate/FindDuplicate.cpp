   // return duplicate element... if n = 5 ->{1, 2, 3, 4, 3} so return 3. and n always present bwt 1 to n-1.

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) {
    int ans = 0;

    for(int i=0; i<arr.size(); i++) {
        ans = ans^arr[i];
    }

    for(int i=1; i<arr.size(); i++) {
        ans = ans^i;
    }
    return ans;

}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int arr;
        vector<int> v;
        for(int i=0; i<n; i++) {
            cin >> arr;
            v.push_back(arr);    
        }
        int result = findDuplicate(v);
        cout << result << endl;
        
    } 
    return 0;
}