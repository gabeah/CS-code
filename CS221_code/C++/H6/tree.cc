#include "tree.hh"


/////////////////////////////////////////////////////////////////////////////
//Travel Function

tree_prt_t traverse(tree_ptr_t tree){
	
	if(!tree -> left){
    		return tree -> left;
	}
	if(!tree -> right){
		return tree -> right;
	}

}

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left,
            tree_ptr_t right)
{
    new_tree = new Tree({key, value, left, right});
    return new_tree;
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
	int* current = tree;
	int* temp = tree;
	if(!current){
		return;
	}
	while(!current -> left && !current -> right){
		while(!tree -> left && !tree -> right){
			temp = traverse(temp);
		}
		delete temp;
		temp = current;
	}

}


std::string
compute_something(some value)
{
	return "hi";
}
//////////////////////////////////////////////////////////////////////////////
std::string
path_to(tree_ptr_t tree, key_type key)
{
	some_value = 12;
	return compute_something(some_value);
}



//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
}
