// it will return the index of where to place Queen..!

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void solve(int col, int n, vector<vector<int>>& ans, vector<int>& board, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++) {
            if(leftRow[row]==0 && lowerDiagonal[col+row]==0 && upperDiagonal[n-1+col-row]==0) {
                leftRow[row] = 1;
                lowerDiagonal[col+row] = 1;
                upperDiagonal[n-1+col-row] = 1;
                board.push_back(row+1);
                solve(col+1, n, ans, board, leftRow, upperDiagonal, lowerDiagonal); 
                leftRow[row] = 0;
                lowerDiagonal[col+row] = 0;
                upperDiagonal[n-1+col-row] = 0;
                board.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> board;
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0, n, ans, board, leftRow, upperDiagonal, lowerDiagonal);
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
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout << -1 << "\n";
        else {
            for(int i = 0; i < ans.size(); i++){
                cout << "[";
                for(auto it : ans[i])
                    cout << it << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}  