// Sum Replacement in binary tree Problem in c++
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
              1                                    1
            /   \         4+8=12                 /   \
           /     \        6+7+3=16              /     \
          2       3                            2      16        
         / \     / \         ---->            / \     / \     ---->     SO ON.... 
        /   \   /   \                        /   \   /   \
       4     5 6     7                      12    5 6     7
      /                                    /
     /                                    /
    8                                    8
*/

void sumReplace(Node* root) {
    if(root == NULL) {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL) {
        root->data += root->left->data;
    }
    if(root->right != NULL) {
        root->data += root->right->data;
    }
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    
    // preorder is 1 2 4 8 5 3 6 7 
    // Sum is      36 19 12 8 5 16 6 7    
    preorder(root);
    cout<<"\n";
    sumReplace(root);
    preorder(root);
    cout<< "\n";

    return 0;
}

// TC is O(n)
//https://youtu.be/xDayqPCWmkY?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ