#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        for(int i=0;i<n/2;i++) {
            cout <<  a[i] << " " << a[i+n/2] << " ";
        }
        if((n%2)!=0) cout<<a[n-1];
        cout << endl;
    }
}
