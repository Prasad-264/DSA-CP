/* matrix : given input matrix, you are require to change it in place without using extra space */

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    
    // transpose matrix
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Swap 1st row with last row
    for(int i=0; i<n/2; i++) {
        swap(matrix[i], matrix[n-i-1]);
    }
    
}

int main()
{
    int t;
    cin>>t; 
    while(t--) {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++) {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
