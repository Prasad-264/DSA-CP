// Height Balanced binary tree Problem in c++
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
bool isBalanced(Node* root, int* height) {
    if(root == NULL) {
        return true;
    }

    int lh = 0, rh = 0;
    if(isBalanced(root->left, &lh) == false) {
        return false;
    }
    if(isBalanced(root->right, &rh) == false) {
        return false;
    }

    *height = max(lh, rh) + 1;
    if(abs(lh - rh) <= 1)  {
        return true;
    } else {
        return false;
    }
    
}




/*
int height(Node* root) {
    if(root = NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalanced(Node* root) {
    if(root == NULL) {
        return true;
    }

    if(isBalanced(root->left) == false) {
        return false;
    }
    if(isBalanced(root->right) == false) {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1) {
        return true;
    } 
    else {
        return false;
    }
}
*/        // TC is O(n*n)

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(9);
    
    // if(isBalanced(root) == true) {
    //     cout<<"Balanced tree" <<"\n";
    // }
    // else {
    //     cout<<"Unbalanced tree" <<"\n";
    // }

    // return 0;

    int height = 0;
    if(isBalanced(root, &height) == true) {
        cout<< "Balanced tree" << "\n";
    }
    else {
        cout<< "Unbalanced tree" <<"\n";
    }
    return 0;
}

// TC is O(n)
//https://youtu.be/bh4eb_6SwRA?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ