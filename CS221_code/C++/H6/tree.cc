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
	if(tree->left_){	// If there is a node to the left of the current node
		destroy_tree(tree->left_); // recurse at the left node
	}
	if(tree->right_){	// If there is a node to the right of the current node
		destroy_tree(tree->right_); // recurse at the right node
	}	
	delete tree; // If there is no subsequent nodes remaining, delete the current node
	return;	// then return out of the recursion
}

//////////////////////////////////////////////////////////////////////////////

std::string 				// This function takes a key and tries to find a path to said node
path_to(tree_ptr_t tree, key_type key) 	
{
	std::string path = ""; 		// Start with an empty string 
	if(tree->key_ == key){ 		// Check if the node we are looking at is the correct node
		return path; 		// return the path string if so
	}
	if(!tree->left_ && !tree->right_){ 	// If there are no available options to check
		path = "-"; 			// Return that the path isn't viable
		return "-";
	}

	if(tree->right_){ 			// Check if there is a right node to search
		std::string r_path = path_to(tree->right_, key); // recurse and check
		if(r_path != "-"){		// If the path is viable
			return "R" + r_path; 	// Include the direction in the path
		}
	}
	if(tree->left_){ 			// Same thing to the left paths and nodes
		std::cout<<"checking left \n";
		std::string l_path = path_to(tree->left_, key);
		std::cout<<path;
		if(l_path != "-") {
			return "L" + l_path;
		}
	}
	return path; 				// Finally return the path
}



//////////////////////////////////////////////////////////////////////////////
tree_ptr_t 					// This function checks a string and returns the node there if there is one
node_at(tree_ptr_t tree, std::string path)
{
	if(path.length()>0){ 			// Assuming the string given isn't empty (also checks if recursion is done)
		if(path[0] == 'L' && tree->left_){ // If the first character is 'L' and there is a left node
			return node_at(tree->left_, path.substr(1,path.length()-1)); // Recurse with the left node
		}
		else if(path[0] == 'R' && tree->right_){ // Same as above with 'R' and a right node
			return node_at(tree->right_, path.substr(1,path.length()-1));
		}
		else{				// If a character besides 'L' or 'R' is given, OR there isn't a node to recieve
			return nullptr; 	// Return null
		}
	}
	return tree; 				// If there are no more characters to check, we have reached our destination, so return the node
}
