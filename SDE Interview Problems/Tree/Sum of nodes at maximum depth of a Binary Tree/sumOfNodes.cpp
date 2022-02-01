// C++ Program to find sum of nodes at maximum
// Depth of the Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Variables to store sum and
// maximum level
int sum = 0, max_level = INT_MIN;

// Binary Tree Node
struct Node {
	int data;
	Node* left;
	Node* right;
};

// Utility function to create and
// return a new Binary Tree Node
Node* createNode(int val)
{

	Node* node = new Node;

	node->data = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Function to find the sum of the node which
// are present at the maximum depth
void sumOfNodesAtMaxDepth(Node* root, int level)
{
	if (root == NULL)
		return;

	// If the current level exceeds the
	// maximum level, update the max_level
	// as current level.
	if (level > max_level) {
		sum = root->data;
		max_level = level;
	}

	// If the max level and current level
	// are same, add the root data to
	// current sum.
	else if (level == max_level) {
		sum = sum + root->data;
	}

	// Traverse the left and right subtrees
	sumOfNodesAtMaxDepth(root->left, level + 1);
	sumOfNodesAtMaxDepth(root->right, level + 1);
}

// Driver Code
int main()
{
	Node* root;
	root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	sumOfNodesAtMaxDepth(root, 0);

	cout << sum;

	return 0;
}
