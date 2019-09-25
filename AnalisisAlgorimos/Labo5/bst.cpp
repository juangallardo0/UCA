#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
	int key;
	struct node *left, *right;
}node;

node *newNode(int item)
{
	node *temp = new node;
	temp->key = item;
	temp->left = temp->right = nullptr;
	return temp;
}

void inorder(node *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}
}

void postorder(node *root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<endl;
	}
}

node *insert(node *node, int key)
{
	if (node == nullptr)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

int main(int argc, char const *argv[])
{
	node *root = nullptr;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	postorder(root);
	return 0;
}