// Count number of Nodes present in binary tree Problem in c++
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

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // 7 Nodes are Present  :)
    cout << countNodes(root) << endl;

    return 0;
}

//https://youtu.be/IHfZaRZFg7s?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ