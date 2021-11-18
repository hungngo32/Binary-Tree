#include"lub.h"
Node* createNode(int data) {
	Node* p = new Node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void inorder(Node* &root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
Node* insert(Node* root,int data) {
	if (root == NULL) {
		return createNode(data);
	}
	Node* tmp = root;
	while (true)
	{
		if (data > tmp->data) {
			if (tmp->right == NULL) {
				tmp->right = createNode(data);
				return root;
			}
			else {
				tmp = tmp->right;
			}
		}
		else {
			if (tmp->left == NULL) {
				tmp->left = createNode(data);
				return root;
			}
			else {
				tmp = tmp->left;
			}
		}
	}
	return root;
}
Node* insert2(Node* root, int data) {
	if (root == NULL) {
		return createNode(data);
	}
	if (root->data < data) {
		root->right = insert2(root->right, data);
	}
	else {
		root->left = insert2(root->left, data);
	}
	return root;
}
Node* minValNode(Node* root) {
	Node* tmp = root;
	while (tmp->left!=NULL)
	{
		tmp = tmp->left;
	}
	return tmp;
}
Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return root;
	}
	if (root->data < data) {
		root->right = deleteNode(root->right, data);
	}
	else if (root->data>data ){
		root->left = deleteNode(root->left, data);
	}
	else {
		//No child
		if (root->left == NULL && root->right == NULL) {
			return NULL;
		}
		else if (root->left == NULL && root->right!=NULL) {
			return root->right;
		}
		else if (root->right == NULL && root->left != NULL) {
			return root->left;
		}
		else {
			Node* tmp = minValNode(root->right);
			root->data = tmp->data;
			root->right = deleteNode(root, tmp->data);
		}
		
	}
	return root;
}
void menu() {
	int ch;
	Node* root = NULL;
	while (true)
	{
		cout << "\n\n\t\tMENU BST";
		cout << "\n\t1.Inorder";
		cout << "\n\t2.Insert";
		cout << "\n\t3.Delete";
		cout << "\nYou choose: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			inorder(root);
			break;
		}
		case 2:
		{
			root = insert(root, 50);
			root = insert(root, 30);
			root = insert(root, 20);
			root = insert(root, 40);
			root = insert(root, 70);
			root = insert(root, 60);
			root = insert(root, 80);
			break;
		}
		case 3:
		{
			root = deleteNode(root, 20);
			cout << "Inorder traversal of the modified tree \n";
			inorder(root);

			break;
		}
		default:

			break;
		}
		system("pause");
	}
}