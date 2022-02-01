#include<bits/stdc++.h>
using namespace std;

bool printSum(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
    if(ind == n) {
        //Condition Satisfied
        if(s == sum) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        //Condition not Satisfied
        else return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printSum(ind+1, ds, s, sum, arr, n) == true) {
        return true;
    }
    s -= arr[ind];
    ds.pop_back();

    if(printSum(ind+1, ds, s, sum, arr, n) == true) return true;
    
    return false;
    
}

int main() {
    int arr[] = {1, 2, 1};
    int sum = 2;
    int n = 3;
    vector<int> ds;

    printSum(0, ds, 0, sum, arr, n);

    return 0;
}