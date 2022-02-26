/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/

class Solution {
private:
    int maxlen(int heights[], int n) {
        stack<int> st; 
        int maxA = 0; 
        //int n = heights.size(); 
        for(int i = 0; i<=n; i++) {
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop(); 
                int width; 
                if(st.empty()) width = i; 
                else width = i - st.top() - 1; 
                
                // cout << i << " " << width << " " << height << endl; 
                maxA = max(maxA, width * height); 
            }
            st.push(i); 
        }
        return maxA;        
    }
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int res = maxlen(M[0], m);
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(M[i][j] == 1) {
                    M[i][j] += M[i-1][j];
                }
            }
            res = max(res, maxlen(M[i], m));
        }
        return res;
    }
};
