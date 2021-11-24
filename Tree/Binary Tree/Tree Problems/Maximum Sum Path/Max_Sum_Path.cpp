// Lowest Common Ancistor of binary tree Problem in c++
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child 
struct Node {
	int data;
	struct Node *left;
    struct Node *right;
	Node(int val){
		data = val;
		left = NULL;
        right = NULL;
	}
};

/*
              1
            /   \
           /     \
          2       3
         / \     / \                
        /   \   /   \
       4     5 6     7

*/

int maxPathSumUtil(Node* root, int &ans) {
    if(root == NULL) {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;

}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //root->right->right->left = new Node(8);
    
    
    cout<<maxPathSum(root);
    return 0;
}
// TC is O(N)
//https://youtu.be/NIJN63astRc?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
