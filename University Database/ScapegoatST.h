/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the ScapegoatST class. It is used to create a scapegoat tree for our database.
*/
#ifndef BST_H
#define BST_H
#include "TreeNode.h"
#include<bits/stdc++.h>
using namespace std;

static int const log32(int n){
  double const log23 = 2.4663034623764317;
  return (int)ceil(log23 * log(n));
}

template <typename T>
class BST{
public:
  BST();
  virtual ~BST();
  int getSize();
  int sizeUnder(TreeNode<T>* node);
  void insert(T d);
  void remove(int d);
  bool contains(T d);
  void printTreeInOrder();
  void printTreePostOrder();
  T getMin();
  T getMax();
  T getMedian();
  T find(int k);
  int getMaxInt(int x, int y);
  TreeNode<T>* getRoot();
  int getHeight(TreeNode<int>* root);
  int getHeightOfRight(TreeNode<T>* root);
  int getHeightOfLeft(TreeNode<T>* root);
  int getDepthOfNode(TreeNode<int>* root, T d);
  bool isNotTooUnbalanced(TreeNode<T>* root);
  T getParent(TreeNode<T>* subTreeRoot, T d);
  T getParent2(TreeNode<T>* subTreeRoot, T d);
  T getParent3(TreeNode<T>* subTreeRoot, T d);
  TreeNode<T>* findParent(TreeNode<T>* node, T d, T parent);
  bool scapeGoatInsert(int studentID, T d);
  int SGInsertWithDepth(TreeNode<T>* newNode);
  void rebuildSG(TreeNode<T>* SGNode);
  int storeInArray(TreeNode<T>* ptr, TreeNode<T>* arr[], int i);
  TreeNode<T>* buildBalancedFromArray(TreeNode<T>** arr, int i, int n);

private:
  int m_size;
  TreeNode<T>* m_root;
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
  void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
  void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
  void insertHelperScapeGoat(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);

};

/*
template <typename T>
static int const log32(int n){
  double const log23 = 2.4663034623764317;
  return (int)ceil(log23 * log(n));
}
*/

template <typename T>
int BST<T>::sizeUnder(TreeNode<T>* node){
  if (node == NULL){
    return 0;
  }
  return 1 + sizeUnder(node->m_left) + sizeUnder(node->m_right);
}
// Default constructor
template <typename T>
BST<T>::BST(){
  m_root = NULL;
  m_size = 0;
}
// Destructor
template <typename T>
BST<T>::~BST(){
  if(m_root != NULL){
    delete m_root;
  }
}
// Gets the size
template <typename T>
int BST<T>::getSize(){
  return m_size;
}
// Inserts to tree
template <typename T>
void BST<T>::insert(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  insertHelper(m_root, newNode);
  ++m_size;
  int h = getHeight(m_root);
  /*
  if (h > log32(m_size)){
    //find scapeGoat
    TreeNode<T>* p = findParent(m_root, d, );
    while (3*getSize() <= 2*getSize()){
      p = getSuccessor(p);
      cout << p->m_data << endl;
    }
    //rebalance tree
  }
  */
}
// Insert helper method
template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
    //newNode->m_parent = subTreeRoot;
  } else if(newNode->m_data < subTreeRoot->m_data){
    insertHelper(subTreeRoot->m_left,newNode);
  } else{
    insertHelper(subTreeRoot->m_right,newNode);
  }
}
// Insert helper method for scapegoat tree
template <typename T>
void BST<T>::insertHelperScapeGoat(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){

}
// Checks to see if tree contains given data
template <typename T>
bool BST<T>::contains(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  return containsHelper(m_root, newNode);

}
// helper for contains method
template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    return false;
  } else if(newNode->m_data == subTreeRoot->m_data){
    return true;
  } else if(newNode->m_data < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,newNode);
  } else{
    return containsHelper(subTreeRoot->m_right,newNode);
  }
}
// Prints the tree in order
template <typename T>
void BST<T>::printTreeInOrder(){
  printTreeInOrderHelper(m_root);
}
// helper to print tree in order
template <typename T>
void BST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printTreeInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data << endl;
    printTreeInOrderHelper(subTreeRoot->m_right);
  }
}
// Prints tree in post order
template <typename T>
void BST<T>::printTreePostOrder(){
  printTreePostOrderHelper(m_root);
}
// Helper to print tree in post order
template <typename T>
void BST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printTreeInOrderHelper(subTreeRoot->m_left);
    printTreeInOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data << endl;
  }
}



/*
template <typename T>
bool BST::iterativeContains(T d){
  if(m_root == NULL){
    return false;
  }
  if(m_root->m_data ==  d){
    return true;
  }
  bool found = false;
  TreeNode<T>* currRoot = m_root;
  while(!found){
    if(d < currRoot->m_data){
      currRoot = currRoot->m_left;
    } else{
      currRoot = currRoot->m_right;
    }
    if(currRoot == NULL){
      found = false;
      break;
    }
    if(currRoot->m_data == d){
      found = true;
      break;
    }

  }
  return found;
}
*/
// Returns the min in tree
template <typename T>
T BST<T>::getMin(){
  //check if empty
  return getMinHelper(m_root);
}
// Helper for get min
template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}
// Returns the max in the tree
template <typename T>
T BST<T>::getMax(){
  //check if empty
  return getMaxHelper(m_root);
}
// Helper to get the max
template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }

}
// Returns the median in the tree
template <typename T>
T BST<T>::getMedian(){
  //check if empty
  return m_root->m_data;
}
// Finds a given integer in the tree. Used to find specific IDs of individuals
template <typename T>
T BST<T>::find(int k){
  if(m_root == NULL)
    return T(); // returns default of whatever datatype it is
  TreeNode<T>* current = m_root;
  while(current->key != k){
    if(k < current->key)
      current = current->m_left;
    else
      current = current->m_right;
    if(current == NULL)
      return T();
  }
  return current->m_data;
}
// Finds a target within the tree given three parameters
template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data != key){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}
// Gets the successor
template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* rightChild){
  while(rightChild->m_left != NULL){
    rightChild = rightChild->m_left;
  }
  return rightChild;
}
// removes a given integer from the tree
template <typename T>
void BST<T>::remove(int d){
  //check if empty
  TreeNode<T>* target = NULL;
  TreeNode<T>* parent = NULL;
  target = m_root;
  //findTarget(d,target,parent);
  if(target == NULL){ //value wasn't in tree, othing to do
    return;
  }
  //check if leaf (including the root)
  if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
    if(target == m_root){ //leaf is the root of tree
      m_root = NULL;
    } else{ //it's not the root
      if(target ==  parent->m_left){
        parent->m_left = NULL;
      } else{
        parent->m_right = NULL;
      }
    }
    //delete target; //free the memory

  } else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
    TreeNode<T>* suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(d); //remove successor treenode originally value
    target->m_data = value;

  } else{ //1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    if(target ==  m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        //cout << "I'm here!" << endl;
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
      //delete target;
  }
  --m_size;
  // cout << "STUDENT DELETED" << endl;
}

// Gets the max int of tree
template <typename T>
int BST<T>::getMaxInt(int x, int y){
  if (x > y){
    return x;
  }
  else{
    return y;
  }
}
// Gets the height of tree
template <typename T>
int BST<T>::getHeight(TreeNode<int>* root){
  if (root == NULL){
    return 0;
  }
  else{
    int leftHeight = getHeight(root->m_left);
    int rightHeight = getHeight(root->m_right);
    return getMaxInt(leftHeight, rightHeight) + 1;
  }
}
// Gets the height of right side of tree
template <typename T>
int BST<T>::getHeightOfRight(TreeNode<T>* root){
  if (root == NULL){
    return 0;
  }
  else{
    return getHeightOfRight(root->m_right) + 1;
  }
}
// Gets the height of left side of tree
template <typename T>
int BST<T>::getHeightOfLeft(TreeNode<T>* root){
  if (root == NULL){
    return 0;
  }
  else{
    return getHeightOfLeft(root->m_left) + 1;
  }
}
// Gets and returns the root of tree
template <typename T>
TreeNode<T>* BST<T>::getRoot(){
  return m_root;
}
// Returns the depth of node 
template <typename T>
int BST<T>::getDepthOfNode(TreeNode<int>* root, T d){
  if (root == NULL){
    return -1;
  }
  int distance = -1;
  if ((root->m_data == d)
        || (distance = getDepthOfNode(root->m_left, d)) >= 0
        || (distance = getDepthOfNode(root->m_right, d)) >= 0){
  
        // Return depth of the node
          return distance + 1;
        }
  return distance;

}
// Checks to make sure tree is not to unbalanced. Returns boolean.
template <typename T>
bool BST<T>::isNotTooUnbalanced(TreeNode<T>* root){
  int left = getHeightOfLeft(root);
  int right = getHeightOfRight(root);
  if (left >= right + 2 || right >= left + 2){
    return false;
  }
  else{
    return true;
  }
}
// Gets the parent in a tree
template <typename T>
T BST<T>::getParent(TreeNode<T>* subTreeRoot, T d)
{
  if (subTreeRoot == NULL){
    return d;
  }
  else if (subTreeRoot->m_data == d){
    return d;
  }
  else if (subTreeRoot->m_right->m_data == d){
    return subTreeRoot->m_data;
  }
  else if (subTreeRoot->m_right->m_data != d){
    if (subTreeRoot->m_left->m_data == d){
      return subTreeRoot->m_data;
    }
    else{
      getParent(subTreeRoot->m_right, d);
    }
  }
  else if (subTreeRoot->m_left->m_data == d){
    return subTreeRoot->m_data;
  }
  else if (subTreeRoot->m_left->m_data != d){
    getParent(subTreeRoot->m_left, d);
  }
  //else{
    //getParent(subTreeRoot->m_right, d);
    //getParent(subTreeRoot->m_left, d);
  //}
}

template <typename T>
T BST<T>::getParent2(TreeNode<T>* subTreeRoot, T d)
{
  if (subTreeRoot == NULL){
    return d;
  }
  else if (subTreeRoot->m_data == d){
    return d;
  }
  else{
    getParent2(subTreeRoot->m_right, d);
    getParent2(subTreeRoot->m_left, d);
  }
}

template <typename T>
T BST<T>::getParent3(TreeNode<T>* subTreeRoot, T d){
  if (subTreeRoot == NULL){
    return d;
  }
  else if (subTreeRoot->m_right->m_data == d){
    return subTreeRoot->m_right->m_parent->m_data;
  }
 }


template <typename T>
TreeNode<T>* BST<T>::findParent(TreeNode<T>* node,
                T d, T parent)
{
    if (node == NULL)
        return node;
    if (node->m_data == d) {
        TreeNode<T>* newNode = new TreeNode<T>(parent);
        return newNode;
    }
    else {
        findParent(node->m_left, d, node->m_data);
        findParent(node->m_right, d, node->m_data);
    }
}
// Insert method for scapegoat tree
template <typename T>
bool BST<T>::scapeGoatInsert(int studentID, T d){

  TreeNode<T>* newNode = new TreeNode<T>(studentID,d);

  int height = SGInsertWithDepth(newNode);

  if (height > log32(m_size)){

    TreeNode<T>* p = newNode->m_parent;

    while (3*sizeUnder(p) <= 2*sizeUnder(p->m_parent)){
      p = p->m_parent;
    }

    rebuildSG(p->m_parent);

  }

}

template <typename T>
int BST<T>::SGInsertWithDepth(TreeNode<T>* newNode){
  TreeNode<T>* w = m_root;

  if (w == NULL){
    m_root = newNode;
    m_size++;
    return 0;
  }

  bool done = false;
  int d = 0;

  do
  {
    if (newNode->m_data < w->m_data){
      if (w->m_left == NULL){
        w->m_left = newNode;
        newNode->m_parent = w;
        done = true;
      }
      else
        w = w->m_left;
    }
    else if (newNode->m_data > w->m_data){
      if (w->m_right == NULL)
      {
        w->m_right = newNode;
        newNode->m_parent = w;
        done = true;
      }
      else
        w = w->m_right;
    }
    else
      return -1;
    d++;
  }
  while (!done);
 
  m_size++;
  return d;
}

template <typename T>
int BST<T>::storeInArray(TreeNode<T>* ptr, TreeNode<T>* arr[], int i){
  if (ptr == NULL)
    return i;
 
  i = storeInArray(ptr->m_left, arr, i);
  arr[i++] = ptr;
  return storeInArray(ptr->m_right, arr, i);
}

template <typename T>
TreeNode<T>* BST<T>::buildBalancedFromArray(TreeNode<T>** arr, int i, int n){
  if (n== 0)
    return NULL;
  int m = n / 2;
 
  // Now arr[m] becomes the root of the new
  arr[i+m]->m_left = buildBalancedFromArray(arr, i, m);
 
  // elements arr[0],...arr[m-1] gets stored in the left subtree
  if (arr[i+m]->m_left != NULL)
    arr[i+m]->m_left->m_parent = arr[i+m];
 
  // elements arr[m+1],....arr[n-1] gets stored in the right subtree

  arr[i+m]->m_right =
    buildBalancedFromArray(arr, i+m+1, n-m-1);
  if (arr[i+m]->m_right != NULL)
    arr[i+m]->m_right->m_parent = arr[i+m];
 
  return arr[i+m];
}
// Rebuilds the scapegoat tree
template <typename T>
void BST<T>::rebuildSG(TreeNode<T>* SGNode){

  int n = sizeUnder(SGNode);

  TreeNode<T>* p = SGNode->m_parent;
  
  TreeNode<T>** arr = new TreeNode<T>* [n];

  storeInArray(SGNode, arr, 0);

  if (p == NULL)
  {
    m_root = buildBalancedFromArray(arr, 0, n);
    m_root->m_parent = NULL;
  }
  else if (p->m_right == SGNode)
  {
    p->m_right = buildBalancedFromArray(arr, 0, n);
    p->m_right->m_parent = p;
  }
  else
  {
    p->m_left = buildBalancedFromArray(arr, 0, n);
    p->m_left->m_parent = p;
  }
}




#endif
