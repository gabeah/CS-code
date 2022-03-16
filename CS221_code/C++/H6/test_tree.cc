// Homework 6
// Gabe H and Julia O
//
// This testing file will construct a tree and do some operation tests

#include "tree.hh"

int main() {
	// This section creates a tree with a root at f, then tests if the tree
	// was made correctly. (Please excuse all the early testing code)
	Tree* a = create_tree(6,12,nullptr,nullptr);
	std::cout<<"tree made\n";
	Tree* b = create_tree(8,23,a,nullptr);
	std::cout<<"tree made\n";
	Tree* c = create_tree(15,-4,nullptr,nullptr);
	std::cout<<"tree made\n";
	Tree* d = create_tree(19,23,b,c);
	std::cout<<"tree made\n";
	Tree* e = create_tree(3,-98,nullptr,nullptr);
	std::cout<<"tree made\n";
	Tree* f = create_tree(29,13,d,e);	
	std::cout<<"tree made\n";
	assert(f!=NULL);
	assert(f->right_->key_==3);

	// Creates a second, smaller, tree. Checks if the tree was made correctly
	// then destroys the tree
	Tree* x = create_tree(1, 10, nullptr, nullptr);
	Tree* y = create_tree(2, 20, nullptr, nullptr);
	Tree* z = create_tree(3, 30, x, nullptr);
	Tree* r = create_tree(4, 40, z, y);
	assert(r);	
	assert(r->left_ && r->right_);
	destroy_tree(r);

	// Creates strings that are the paths to nodes, then prints them
	std::string path = path_to(f,6);
	std::string path2 = path_to(f,15);
	std::string path3 = path_to(f,3);
	std::cout<<path<<"\n";
	std::cout<<path2<<"\n";
	std::cout<<path3<<"\n";

	// Creates pointers for nodes that are found using 'node_at' then prints them
	// it also takes the key at the node and returns it.
	// Note: a segfault occurs if any of the follows didn't actually point to a node.
	// This is because the assignment wanted the node, and in my testing I pulled a value
	// from a node to make sure my code worked right.
	Tree* follow = node_at(f,"LR");
	Tree* follow2 = node_at(f,"LLL");
	Tree* follow3 = node_at(f,"R");
	Tree* follow4 = node_at(f,"RL");

	std::cout<<follow->key_<<"\n";
	std::cout<<follow2->key_<<"\n";
	std::cout<<follow3->key_<<"\n";
	std::cout<<follow4->key_<<"\n";

	// Finally destroys the tree we have done work on
	destroy_tree(f);

	// End program
	return 0;

}
