// CS221 HW8 - Huffman Encoding (huffman.cc)
// By Yik Yin Cheuk

#include "huffman.hh"
#include "htree.hh"
#include "hforest.hh"
#include <iostream>
#include <vector>

Huffman::Huffman(){
  freq = {};                      // Frequency table starts empty
  freq.assign(ALPHABET_SIZE, 0);  // Any size of ALPHABET_SIZE
  root = createTree();             // Builds some tree so it isn't nullptr
}

// encodes symbol into sequence of bits and updates frequency table
Huffman::bits_t
Huffman::encode(int symbol){
  Huffman huff;
  auto dir_bits = huff.root->HTree::path_to(symbol); // is path_to not terminating??
  bits_t boolBits;
  for (HTree::Direction i : *dir_bits){
    if (i == HTree::Direction(0)){
      boolBits.push_back(false);
    } else {
      boolBits.push_back(true);
    }
  }
  freq.at(symbol) += 1; // update the frequency
  return boolBits;
}

int Huffman::decode(bool bit){
  // if root isn't nullptr...
  if(root){
  }
    else{
      root = createTree();
  }
  if(bit == 0){
    root = root->get_child(HTree::Direction::LEFT);
  }
    else {
    root = root->get_child(HTree::Direction::RIGHT);
    }
    // if root is a leaf, update frequency, reset root to nullptr, return symbols
    if(!root->get_child(HTree::Direction::RIGHT) && !root->get_child(HTree::Direction::LEFT)){
      int symbol = root -> get_key();
    root = nullptr;
    freq.at(symbol) += 1; // update frequency
      return symbol; // returns symbol
    }
    else{
      return root -> get_key();
    }
}

// Assumes there exists a member called 'freq' and then returns a Huffman tree
Huffman::tree_ptr_t
Huffman::createTree(){
  HForest heap({});
  for (int i = 0; i < ALPHABET_SIZE; i++){
    HTree::tree_ptr_t newTree(new HTree(i, freq.at(i)));
    heap.add_tree(newTree);
  }
  int i = 257;
  while(heap.size() > 1){
    HTree::tree_ptr_t l = heap.pop_top(); // pops the lowest value off the heap_size
    HTree::tree_ptr_t r = heap.pop_top(); //pops the second lowest value
    // checking for negaive keys
    int tempVal = l->get_value() + r->get_value();
    HTree::tree_ptr_t temp = HTree::tree_ptr_t(new HTree(i, tempVal,l,r));
      i += 1;
    heap.add_tree(temp);
  }
  // pop_top returns huffman tree
  return heap.pop_top();
}
