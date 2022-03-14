#include "tree.hh"

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    new Tree = ({key, value, left, right})
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
	int* current = tree;
	int* temp = tree;
	if(!tree -> left){
		temp = tree -> left;
		destroy_tree(tree_prt_t temp);
    	}
	current = temp;
	if(!tree -> right){
		temp = tree -> right;
	}
}


//////////////////////////////////////////////////////////////////////////////
std::string
path_to(tree_ptr_t tree, key_type key)
{
}


//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
}
