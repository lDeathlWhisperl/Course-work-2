#include <iostream>
#include "Tree.h"

void Tree::insert(int num)
{
	Node* node;
	if (size == 0)
	{
		root = new Node;
		root->data = num;
		root->left = root->right = NULL;
		node = root;
		size++;
		return;
	}
	
	Node* temp = new Node;
	temp->left = NULL;
	temp->data = num;
	temp->right = NULL;

	node = root;

	while (node && node->data != num)
	{
		if (num < node->data && node->left == NULL)
		{
			node->left = temp;
			size++;
			return;
		}
		if (node->data < num && node->right == NULL)
		{
			node->right = temp;
			size++;
			return;
		}
		if (num < node->data)
			node = node->left;
		else
			node = node->right;
	}
}

int Tree::getSize()
{
	return size;
}

void Tree::print()
{
	printTree(root, nullptr, false);
}

int Tree::min()
{
	Node* node = root;
	while (node->left)
		node = node->left;

	return node->data;
}

int Tree::max()
{
	Node* node = root;
	while (node->right)
		node = node->right;

	return node->data;
}

void Tree::showTrunks(Trunk* p)
{
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;

}
void Tree::printTree(Node* root, Trunk* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	std::string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, true);

	if (!prev) {
		trunk->str = "-->";
	}
	else if (isLeft)
	{
		trunk->str = ".-->";
		prev_str = "   |";
	}
	else {
		trunk->str = "`-->";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	std::cout << " " << root->data << std::endl;

	if (prev) {
		prev->str = prev_str;
	}
	trunk->str = "   |";

	printTree(root->left, trunk, false);
}