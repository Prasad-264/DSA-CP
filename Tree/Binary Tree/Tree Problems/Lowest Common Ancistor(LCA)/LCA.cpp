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

Node* LCA(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == n1 || root->data == n2) {
        return root;
    }
    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2) ;

    if(leftLCA && rightLCA) {
        return root;
    }

    if(leftLCA != NULL) {
        return leftLCA;
    }
    return rightLCA;
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
    
    int n1 = 4;
    int n2 = 7;
    Node* lca = LCA(root, n1, n2);
    
    if(lca == NULL) {
        cout << "LCA doesn't exist" << endl;
    } else {
        cout << "LCA : " << lca->data << endl;
    }
    
    return 0;
}
// TC is O(N)
//https://youtu.be/JW-9nhktGGA?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
