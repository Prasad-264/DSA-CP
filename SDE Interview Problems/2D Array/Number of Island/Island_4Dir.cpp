/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

class Solution {
private:
    void dfs(vector<vector<char>>& matrix, int x, int y, int row, int col) {
        // Check boundry conditions
        if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] != '1') return;
        
        // mark current cell as visited
        matrix[x][y] = '2';
        
        // check in 4 directions
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++) {
            dfs(matrix, x + dx[i], y + dy[i], row, col);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int island = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, row, col);
                    island++;
                }
            }
        }
        return island;
    }
};
