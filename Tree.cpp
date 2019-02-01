#include "Tree.h"
#include <iostream>
using namespace std;

Node::Node() : data(-1), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}

// In RB trees, every node is added as RED and properties are fixed in insertFix()
Node::Node(int data_) : data(data_), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}

void Node::setData(int key) {
  data = key;
}

void Node::setLeft(Node* node) {
  left = node;
}

void Node::setRight(Node* node) {
  right = node;
}

void Node::setParent(Node* node) {
  parent = node;
}

void Node::setColour(int newColour) {
  colour = newColour;
}

int Node::getData() {
  return data;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getParent() {
  return parent;
}

int Node::getColour() {
  return colour;
}

// New tree
Tree::Tree() : root(nullptr), nil(nullptr) {
  Node* node = new Node();
  nil = node;
  nil->setColour(BLACK);
  nil->setParent(nullptr);
  nil->setLeft(nullptr);
  nil->setRight(nullptr);
  root = nil;
}

// Point children of node to nil
void Tree::setLeaf(Node* node) {
  node->setLeft(nil);
  node->setRight(nil);
}

void Tree::addValue(int key) {
  Node* node = new Node(key);
  node->setData(key);

  Node* xNode = root;
  Node* yNode = root;
  // Iterate down the tree until proper spot found
  while(xNode != nil) {
    yNode = xNode;
    if(key < xNode->getData())
      xNode = xNode->getLeft();
    else
      xNode = xNode->getRight();
  }
  // If tree is empty
  if(yNode == nil){
    root = node;
    root->setColour(BLACK);
    setLeaf(root);
  }
  else if(key < yNode->getData()){
    yNode->setLeft(node);
    setLeaf(node);
  }
  else{
    yNode->setRight(node);
    setLeaf(node);
  }
  // ******** when implemented call fix on node
}

Node* Tree::successor(Node* node) {
  Node* xNode = node->getRight();
  Node* yNode = xNode;
  while(xNode != nil) {
    yNode = xNode;
    if(yNode->getLeft() != nil)
      xNode = yNode->getLeft();
  }
  return yNode;
}

Node* Tree::predecessor(Node* node) {
  Node* xNode = node->getLeft();
  Node* yNode = xNode;
  while(xNode != nil) {
    yNode = xNode;
    if(yNode->getRight() != nil)
      xNode = yNode->getRight();
  }
  return yNode;
}
