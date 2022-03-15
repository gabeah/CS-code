// Homework 6
// Gabe H and Julia B
//
// This testing file will construct a tree and do some operation tests

#include "tree.hh"
#include <assert.h>

int main() {

	Tree* a = create_tree(6,12,nullptr,nullptr);
	Tree* b = create_tree(8,23,a,nullptr);
	assert(b!=NULL);
	return 0;

}
