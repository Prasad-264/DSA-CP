// Delete in binary search tree Problem in c++
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

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while(curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key) {
    
    if(key < root->data) {
        root->left = deleteInBST(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteInBST(root->right, key);
    }
    // Case 1 & 2
    else{
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;

}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    
    inorder(root);
    cout << endl;
    root = deleteInBST(root, 6);
    inorder(root);
    
    return 0;
}
//TC is O(log n)
//https://youtu.be/kU9Lv3e_kxs?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
