// Left View of binary tree Problem in c++
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

void leftView(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();                    //according to level size
        for(int i=1; i<=n; i++) {
            Node* curr = q.front();
            q.pop();

            if(i == 1) {                      //left most value of queue
                cout << curr->data << " ";
            }

            if(curr->left != NULL) {
                q.push(curr->left);
            }

            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
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
    
    // Left view of binary tree
    leftView(root);
    return 0;
}
//TC is O(n)
//https://youtu.be/zDkNaQYusu0?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
