// Is valid BST in binary search tree Problem in c++
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

bool isBST(Node* root, Node* min=NULL, Node* max=NULL) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->data <= min->data) {
        return false;
    }

    if(max != NULL && root->data >= max->data) {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    //root->left->left->left = new Node(1);
    
    if(isBST(root, NULL, NULL)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Invalid BST" << endl;
    }
    
    return 0;
}
//TC is O(N)
//https://youtu.be/_XgTN72fguk?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
