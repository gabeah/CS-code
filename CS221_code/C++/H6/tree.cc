#include "tree.hh"
#include <string>


/////////////////////////////////////////////////////////////////////////////
//Travel Function

tree_ptr_t traverse(tree_ptr_t tree){
	
	if(!tree -> left_){
    		return tree -> left_;
	}
	if(!tree -> right_){
		return tree -> right_;
	}
	return nullptr;

}

//////////////////////////////////////////////////////////////////////////////
tree_ptr_t
create_tree(const key_type& key,
            const value_type& value,
            tree_ptr_t left_,
            tree_ptr_t right_)
{
    Tree* new_tree = new Tree({key, value, left_, right_});
    return new_tree;
}


//////////////////////////////////////////////////////////////////////////////
void
destroy_tree(tree_ptr_t tree)
{
	Tree* current = tree;
	Tree* temp = tree;
	if(!current){
		return;
	}
	while(!current -> left_ && !current -> right_){
		while(!tree -> left_ && !tree -> right_){
			temp = traverse(temp);
		}
		delete temp;
		temp = current;
	}

}

//////////////////////////////////////////////////////////////////////////////

std::string
path_to(tree_ptr_t tree, key_type key)
{
	std::string path = "";
	if(tree->key_ == key){
		return path;
	}
	else if(!tree->left_ && !tree->right_){
		return path;
	}
	else if(tree->left_){
		path.push_back('L');
		return path_to(tree->left_, key);
	}
	else if(tree->right_){
		path.push_back('R');
		return path_to(tree->left_, key);
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
