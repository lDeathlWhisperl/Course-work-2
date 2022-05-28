#include <iostream>
#include "Tree.h"

int main()
{
	Tree tr;
	tr.insert(50);
	tr.insert(34);
	tr.insert(75);
	tr.insert(68);
	tr.insert(22);
	tr.insert(64);
	tr.insert(80);
	tr.insert(23);

	tr.print();
	return 0;
}