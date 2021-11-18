#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* createNode(int data) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "Memory error\n";
	}
	else {
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
Node* insert(Node* root, int data) {
	if (root == NULL) {
		root = createNode(data);
		return root;
	} 
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* tmp = q.front();
		q.pop();
		if (tmp->left != NULL) {
			q.push(tmp->left);
		}
		else {
			tmp->left = createNode(data);
			return root;
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
		}
		else {
			tmp->right = createNode(data);
			return root;
		}
	}
}
void deleteDeepest(Node* root,Node*tmp) {
	if (root == NULL) {
		return;
	} 
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp == tmp) {
			temp = NULL;
			delete tmp;
			return;
		}
		if (temp->left == tmp) {
			temp->left = NULL;
			delete tmp;
			return;
		}
		else {
			q.push(temp->left);
		}
		if (temp->right == tmp) {
			temp->right = NULL;
			delete tmp;
			return;
		}
		else {
			q.push(temp->right);
		}

	}
}
Node* deletion(Node* root, int key) {
	if (root == NULL) {
		cout << "\nEmpty!";
		return NULL;
	} 
	if (root->left == NULL && root->right == NULL) {
		if (root->data == key)
			return NULL;
		else
			return root;
	}
	queue<Node*> q;
	q.push(root);
	Node* find = NULL;
	Node*temp=new Node;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->data == key) {
			find = temp;
		}
		if (temp->left!=NULL) {
			q.push(temp->left);
		}
		if (temp->right!=NULL) {
			q.push(temp->right);
		}
	}
	if (find != NULL) {
		int x = temp->data;
		deleteDeepest(root, temp);
		find->data = x;

	}
	return root;
}
void display(Node* root) {
	if (root == NULL) {
		return;
	}
	display(root->left);
	cout << root->data << " ";
	display(root->right);
}
int main() {
	Node* root =createNode(10);
	root->left = createNode(11);
	root->left->left = createNode(7);
	root->left->right = createNode(12);
	root->right = createNode(9);
	root->right->left = createNode(15);
	root->right->right = createNode(8);

	cout << "Inorder traversal before deletion : ";
	display(root);

	int key = 11;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	display(root);

	return 0;
}