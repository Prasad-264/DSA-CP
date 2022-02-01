#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 9;
    int A[9] = {1, 4, 4, 4, 4, 9, 9, 10, 11};

    // Find the first occurrence of X in a sorted array. If no number exist print -1.
    int ind = lower_bound(A, A+n, 4)-A;
    if(ind != n && A[ind] == 4) cout << ind << endl;
    else cout << -1 << endl;

    // Find the last occurrence of X in a sorted array. If no number exist print -1.
    int ind1 = upper_bound(A, A+n, 9)-A;
    ind1--;
    if(ind1>=0 && A[ind1] == 9) cout << ind1 << endl;
    else cout << -1 << endl;

    // Find the largest number smaller than X in sorted array. If no number exist print -1.
    int ind2 = lower_bound(A, A+n, 9)-A;
    ind2--;
    if(ind2>=0) cout << A[ind2] << endl;
    else cout << -1 << endl;

    // Find the smallest number greater than X in sorted array. If no number exist print -1.
    int ind3 = upper_bound(A, A+n, 9)-A;
    if(ind3<n) cout << A[ind3] << endl;
    else cout << -1 << endl;

    
    
    return 0;
}