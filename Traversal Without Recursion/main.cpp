//1) Create an empty stack S.
//2) Initialize current node as root
//3) Push the current node to Sand set current = current->left until current is NULL
//4) If current is NULLand stack is not empty then
//a) Pop the top item from stack.
//b) Print the popped item, set current = popped_item->right
//c) Go to step 3.
//5) If current is NULLand stack is empty then we are done.
#include<iostream>
#include<stack>
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
void traversal(Node* root) {
	if (root == NULL) {
		return;
	}
	stack<Node*> s;
	while (!s.empty()||root!=NULL)
	{
		while (root!=NULL)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		cout << root->data << " ";
		root = root->right;
	}
}
int main() {
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	traversal(root);
	return 0;
}