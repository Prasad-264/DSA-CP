#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
    if(col == n) {
        ans.push_back(board);
      return;
    }
    for( int row=0;row<n;row++) {
        if(left[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0 ) {
            board[row][col] = 'Q';
            left[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            solve(col+1, board,ans,left, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            left[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
            

        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<int> left(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0, board, ans, left, upperDiagonal, lowerDiagonal, n);
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;        
        Solution ob;
        vector<vector<string>> ans = ob.solveNQueens(n);
        if(ans.size() == 0)
            cout << -1 << "\n";
        else {
            for(int i = 0; i < ans.size(); i++){
                cout << "[";
                for(auto it : ans[i])
                    cout << it << " , ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}