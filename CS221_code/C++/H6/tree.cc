#include "tree.hh"
#include <string>

/////////////////////////////////////////////////////////////////////////////
//Travel Function 			//NOTE: this function is no longer being used
/*
tree_ptr_t traverse(tree_ptr_t tree){ 	// This is a function to travel the tree
	
	if(tree -> left_){ 		// Checks if there is a node to the left
    		return tree -> left_;
	}
	if(tree -> right_){ 		// Checks if there is a node to the right
		return tree -> right_;
	}
	return nullptr; 		// If no nodes are there, then return null

}
*/
//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key, 		// This function creates a new node
            const value_type& value,
            tree_ptr_t left_,
            tree_ptr_t right_)
{
    Tree* new_tree = new Tree({key, value, left_, right_}); 	// create the node
    return new_tree; 						// return the node
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree) 	// This function is for destroying a tree
{
	if(tree->left_){
		destroy_tree(tree->left_);
	}
	if(tree->right_){
		destroy_tree(tree->right_);
	}	
	delete tree;
	return;	
}

//////////////////////////////////////////////////////////////////////////////

std::string
path_to(tree_ptr_t tree, key_type key)
{
	std::string path = "";
	if(tree->key_ == key){
		return path;
	}
	if(!tree->left_ && !tree->right_){
		return "-";
	}
	if(tree->left_){
		std::cout<<"checking left \n";
		std::string l_path = path_to(tree->left_, key);
		if(l_path != "-") {
			path = l_path;
			path.push_back('L');
			return path;
		}
	}
	if(tree->right_){
		std::cout<<"checking right \n";
		std::string r_path = path_to(tree->right_, key);
		if(r_path != "-"){
			path = r_path;
			path.push_back('R');
			return path;
		}
	}
	return path;
}



//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
node_at(tree_ptr_t tree, std::string path)
{
	if(path.length()>0){
		if(path[0] == 'L' && tree->left_){
			return node_at(tree->left_, path.substr(1,path.length()-1));
		}
		else if(path[0] == 'R' && tree->right_){
			return node_at(tree->right_, path.substr(1,path.length()-1));
		}
		else{	
			return nullptr;
		}
	}
	return tree;
}
