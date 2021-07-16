
#include <iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


Node* Insert(Node* root, int data) {

	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}

	return root;
}


bool Search(Node* root, int data) {

	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);


}


Node* FindMin(Node* root)
{
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}


Node* Delete(Node *root, int data) {

	if (root == NULL) return root;
	else if (data < root->data)  root->left = Delete(root->left, data);
	else if (data > root->data)  root->right = Delete(root->right, data);
	else {
		// case 1: No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}

		// case 2: 1 child
		else if (root->left == NULL) {
			Node* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right == NULL) {
			Node* tmp = root;
			root = root->left;
			delete tmp;
		}
		// case 3
		else {
			Node* tmp = FindMin(root->right);
			root->data = tmp->data;
			root->right = Delete(root->right, tmp->data);

		}



	}

	return root;

}


void LevelOrderTraversal(Node* root) {
	queue<Node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		Node* current = Q.front();
		cout << current->data << ", ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}


void preorder(Node* root) {
	if (root == NULL) return;

	cout << root->data << ", ";
	preorder(root->left);
	preorder(root->right);
}


void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	cout << root->data << ", ";
	Inorder(root->right);
}

void Postorder(Node* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << ", ";
}


int main()
{

	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	root = Delete(root, 8);


	int number;
	cout << "Enter a number: " << endl;
	cin >> number;

	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";

	cout << "Level Order Traversal: " << endl;
	LevelOrderTraversal(root);
	cout << endl;
	cout << "Preorder traversal" << endl;
	preorder(root);

	cout << endl;
	cout << "Inorder traversal" << endl;
	Inorder(root);

	cout << endl;
	cout << "Postorder traversal" << endl;
	Postorder(root);

	return 0;
}
