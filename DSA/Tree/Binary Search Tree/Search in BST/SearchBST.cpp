// Search in binary search tree Problem in c++
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

Node* searchInBST(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == key) {
        return root;
    }
    //if key is less than root->data search in left sub tree
    if(root->data > key) {
        return searchInBST(root->left, key);
    }
    //if key is greater than root->data
    return searchInBST(root->right, key);

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
    
    if(searchInBST(root, 6) == NULL) {
        cout << "Key doesn't exists" << endl;
    } else {
        cout << "Key Exists" << endl;
    }
    return 0;
}
//TC is O(log n)
//https://youtu.be/kU9Lv3e_kxs?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
