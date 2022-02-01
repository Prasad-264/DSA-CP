// Count Diameter of binary tree Problem in c++
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
      /
     /
    8  
*/

int diameter(Node* root, int* height) {
    if(root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = diameter(root->left, &lh);
    int rDiameter = diameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh,rh)+1;

    return max(currDiameter, max(lDiameter, rDiameter));
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
    
    // Diameter is 6  8->4->2->1->3->7    
    int height = 0;
    cout << diameter(root, &height) << endl;

    return 0;
}

// TC is O(n)
//https://youtu.be/9fj_-Sr84CU?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ