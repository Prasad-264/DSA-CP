// print same elements present in arr1 and arr2

#include<bits/stdc++.h>
using namespace std;

void findIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i=0, j=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, m ; 
        cin >> n >> m;
        int arr1, arr2;
        vector<int> v1;
        for(int i=0; i<n; i++) {
            cin >> arr1;
            v1.push_back(arr1);    
        }
        vector<int> v2;
        for(int i=0; i<m; i++) {
            cin >> arr2;
            v2.push_back(arr2);
        }
        findIntersection(v1, n, v2, m);
        
    } 
    return 0;
}