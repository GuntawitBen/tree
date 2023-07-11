#include "node.h"

class BST {
private:
  int size;
  TreeNode* rootPtr; //first node
public:
  BST();
  ~BST();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all(int = 0);
  void inOrder(TreeNodePtr);   //left, data, right
  void preOrder(TreeNodePtr);  //data, left, right
  void postOrder(TreeNodePtr); //left, right, data
  void printTree(TreeNodePtr,int);
};

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNode* new_node = new TreeNode(value);
  if (new_node != nullptr) {
    if (rootPtr == nullptr) {
      rootPtr = new_node;
    } 
    else {
      TreeNode* t = rootPtr;
      while (!inserted) {
        if (value <= t->get_data()) {
          if (t->move_left() != nullptr)
            t = t->move_left();
          else {
            t->set_left(new_node);
            inserted = 1;
          }
        } 
        else { //if value more than root
          if (t->move_right() != nullptr)
            t = t->move_right();
          else {
            t->set_right(new_node);
            inserted = 1;
          }
        }
      }
    }
    ++size;
  }
}

void BST::inOrder(TreeNodePtr treePtr) { //left, data, right
  if (treePtr == nullptr) return;
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_data(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right  
} //===========================================================

void BST::preOrder(TreeNodePtr treePtr) { //data, left, right
  if(treePtr == nullptr) return;
  cout << setw(3) << treePtr->get_data();
  preOrder(treePtr->move_left());
  preOrder(treePtr->move_right());
} //===========================================================

void BST::postOrder(TreeNodePtr treePtr) { //left, right, data
  if (treePtr == nullptr) return;
  postOrder(treePtr->move_left());
  postOrder(treePtr->move_right());
  cout << setw(3) << treePtr->get_data();
} //===========================================================

void BST::printTree(TreeNodePtr treePtr,int l) {
  if (treePtr) {
    printTree(treePtr->move_right(), l+1);
    cout << setw(l*3) << treePtr->get_data() << endl;
    printTree(treePtr->move_left(), l+1);
  }                           
} //===========================================================

void BST::print_all(int option) {
  switch (option) {
  case 0:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    break;
  default:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
    printTree(rootPtr,0);
    cout << endl;
  }
}

void BST::kill(TreeNode* treePtr) {
  if (treePtr) {
    kill(treePtr->move_left());  // Recursively delete left subtree
    kill(treePtr->move_right()); // Recursively delete right subtree
    delete treePtr;              // Delete current node
  }
}

BST::BST() {
  rootPtr = nullptr;
  size = 0;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    kill(rootPtr);
}
