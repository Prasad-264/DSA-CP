// C++ program for different tree traversals
#include <iostream>
using namespace std;

// A binary tree node has data, pointer to left child and a pointer to right child 
struct Node {
	int data;
	struct Node *left, *right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

// Given a binary tree, print its nodes in preorder
void Preorder(struct Node* root)
{
	if (root == NULL)
		return;

	// first print data of node 
	cout << root->data << " ";

	// then recur on left subtree 
	Preorder(root->left);

	// now recur on right subtree 
	Preorder(root->right);
}


// Given a binary tree, print its nodes in inorder
void Inorder(struct Node* root)
{
	if (root == NULL)
		return;

	// first recur on left child 
	Inorder(root->left);

	// then print the data of node 
	cout << root->data << " ";

	// now recur on right child 
	Inorder(root->right);
}

// Given a binary tree, print its nodes according to the "bottom-up" postorder traversal. 
void Postorder(struct Node* root)
{
	if (root == NULL)
		return;

	// first recur on left subtree
	Postorder(root->left);

	// then recur on right subtree
	Postorder(root->right);

	// now deal with the node
	cout << root->data << " ";
}




// Driver program to test above functions
int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

	cout << "\nPreorder traversal of binary tree is \n";
	Preorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	Inorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	Postorder(root);

	return 0;
}
