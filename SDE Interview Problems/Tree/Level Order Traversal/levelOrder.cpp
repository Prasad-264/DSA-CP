/*
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level). 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                level.push_back(temp->val);                
            }
            ans.push_back(level);
        }
        return ans;
    }
};