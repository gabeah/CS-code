// Homework 6
// Gabe H and Julia B
//
// This testing file will construct a tree and do some operation tests

#include "tree.hh"

int main() {

	Tree* a = create_tree(6,12,nullptr,nullptr);
	Tree* b = create_tree(8,23,a,nullptr);
	return 0;

}
