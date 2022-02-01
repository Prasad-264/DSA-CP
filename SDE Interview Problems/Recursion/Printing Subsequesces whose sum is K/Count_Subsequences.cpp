#include<bits/stdc++.h>
using namespace std;

int printSum(int ind, int s, int sum, int arr[], int n) {
    if(ind == n) {
        //Condition Satisfied
        if(s == sum) return 1;
        
        //Condition not Satisfied
        else return 0;
    }

    s += arr[ind];
    int l = printSum(ind+1, s, sum, arr, n);
    s -= arr[ind];
    //Not pick..!
    int r = printSum(ind+1, s, sum, arr, n);
    
    return l + r;
    
}

int main() {
    int arr[] = {1, 2, 1};
    int sum = 2;
    int n = 3;

    cout << printSum(0, 0, sum, arr, n);

    return 0;
}