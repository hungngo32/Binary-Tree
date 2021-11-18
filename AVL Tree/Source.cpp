#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left, * right;
	int height;
};
int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
Node* createNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
Node* rightRotate(Node* x) {
	Node* y = x->left;
	Node* tmp = y->right;
	x->left = tmp;
	y->right = x;

	x->height = max(height(x->left), height(x->left)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}
Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* tmp = y->left;
	x->right = tmp;
	y->left = x;
	x->height = max(height(x->left), height(x->left)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}
int getBalance(Node* root) {
	if (root == NULL) return 0;
	return height(root->left) - height(root->right);
}
Node* insert(Node* root, int data) {
	if (root == NULL) {
		return createNode(data);
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);
	}
	root->height = 1 + max(height(root->right), height(root->left));
	int balance = getBalance(root);
	//Left left
	if (balance > 1 && data < root->left->data) {
		return rightRotate(root);
	}
	//Right right
	if (balance<-1 && data>root->right->data) {
		return leftRotate(root);
	}
	//Right left
	if (balance < -1 && data < root->right->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	//Left right
	if (balance > 1 && data > root->left->data) {
		root->right = rightRotate(root->left);
		return leftRotate(root);
	}
}
void preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main() {
	Node* root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the "
		"constructed AVL tree is \n";
	preOrder(root);

	return 0;
	return 0;
}