#include "bst.h"

int main(void){
	BST<int> tree;
	tree.insertIterative(10);
	tree.insertIterative(5);
	tree.insertIterative(25);
	tree.print(2);
}