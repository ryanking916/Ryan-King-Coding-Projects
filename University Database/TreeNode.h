/*
Ryan King
2385162
Ryanking@chapman.edu
CPSC-350-02
Programming Assignment 5: The GOAT
Description: This is the Tree Node class we worked on in class. It contains the methods and variables needed to work with and utilize tree nodes.
*/
#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
class TreeNode{
public:
  TreeNode(int k, T d);
  virtual ~TreeNode();
  T getData();
  template <typename S>
  friend class BST;
private:
  T m_data;
  int key;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;
  TreeNode<T>* m_parent;
};
template <typename T>
TreeNode<T>::TreeNode(int k, T d){
  key = k;
  m_data = d;
  m_left = NULL;
  m_right = NULL;
  m_parent = NULL;
}
template <typename T>
TreeNode<T>::~TreeNode(){
  if(m_left != NULL){
    delete m_left;
  }
  if(m_right != NULL){
    delete m_right;
  }
}
template <typename T>
T TreeNode<T>::getData(){
  return m_data;
}

#endif