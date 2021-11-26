// Sorted Array to construct BST in binary search tree Problem in c++
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
              5
            /   \
           /     \
          3       8
         / \     / \                
        /   \   /   \
       2     4 6     9

*/

Node* sortedArrayToBST(int arr[], int start, int end) {
    if(start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

void preorderPrint(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    // Node* root = new Node(5);
    // root->left = new Node(3);
    // root->right = new Node(8);
    // root->left->left = new Node(2);
    // root->left->right = new Node(4);
    // root->right->left = new Node(6);
    // root->right->right = new Node(9);
    //root->left->left->left = new Node(1);
    
    int arr[] = {10, 20, 30, 40, 50};
    Node* root = sortedArrayToBST(arr, 0, 4);
    preorderPrint(root);
    cout << endl;
    
    return 0;
}
//TC is O(N log N)
//https://youtu.be/C59kWTK4_Zs?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
