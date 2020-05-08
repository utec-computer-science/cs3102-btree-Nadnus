#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <chrono> 
#include <stdio.h>
#include <unistd.h>
 
#include "Tree.h"


// CHICOS UNANSE AL ZOOM
// ZOOM: https://utec.zoom.us/j/815711285

int main() {
  typedef BSTNode<float> bst_node;
  typedef BNode<int> b_node;
  typedef Tree<b_node> b_tree;

  b_tree tree(5); 
  tree.insert(30);

  tree.insert(10);
  
  tree.insert(60);
  
  tree.insert(50);
  
  tree.insert(150);
  
  tree.insert(200);
  tree.insert(210);
  tree.print(std::cout);
  
  //cout << tree << endl;
}

// https://repl.it/login?goto=/join/znxxkwam-carlosarias3
