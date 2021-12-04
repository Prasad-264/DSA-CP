// n is given odd number. we have to find which number is occured twice 
#include<bits/stdc++.h>
using namespace std;

int uniqueEle(int arr[], int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = ans^arr[i];     // 3^3=0 or a^a=0 or a^0=a
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int result = uniqueEle(arr, n);
        cout << result << endl;
    }
    
    
    return 0;
}

//Codestudio