#pragma once
#include <iomanip>

struct Node
{
	int data;
	Node* left, * right;
};

struct Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

class Tree
{
private:
	int   size;
	Node* root;

	void showTrunks(Trunk* p);

	void printTree(Node* root, Trunk* prev, bool isLeft);
public:
	Tree() : size(0), root(NULL) {};

	void insert(int num);

	int getSize();

	void print();

	int min();

	int max();
};