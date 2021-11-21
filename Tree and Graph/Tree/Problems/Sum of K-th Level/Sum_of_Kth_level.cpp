// Sum of K-th Level Problem in c++
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

int SumofK(Node* root, int K) {
    if(root == NULL) {
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        if(node != NULL) {
            if(level == K) {
                sum += node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);        
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }        
    }
    return sum;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // Sum of level 2 is 4+5+6+7 = 22
    cout << SumofK(root,2) << endl;
    cout << SumofK(root, 1);

    return 0;
}