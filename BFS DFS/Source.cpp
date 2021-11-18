#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left, * right;

};
Node* createNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int height(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int rheight = height(root->right);
		int lheight = height(root->left);
		if (rheight > lheight) return rheight + 1;
		else return lheight + 1;
	}
}
void printCurrentLevel(Node* root, int level) {
	if (root == NULL) {
		return;
	}
	if (level == 1) {
		cout << root->data;
		cout << endl;
	}
	else if (level>1) {
	//	cout << "Level " << level << ": ";
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);

	}
}
void printLevelOrder(Node* root) {
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printCurrentLevel(root, i);
	}
}
int main() {
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	printLevelOrder(root);
	return 0;
}