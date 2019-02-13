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
    root->setParent(nil);
    nil->setLeft(root);
    nil->setRight(root);
    nil->setColour(BLACK);
  }
  // Tree isn't empty
  else if(key < yNode->getData()){
    yNode->setLeft(node);
    setLeaf(node);
    node->setParent(yNode);
  }
  else{
    yNode->setRight(node);
    setLeaf(node);
    node->setParent(yNode);
  }
  setLeaf(node);
  insertFix(node);
}



void Tree::insertFix(Node* node) {
  Node* y = nullptr;
  while(node->getParent()->getColour() == RED && node->getColour() == RED) {
    if(node->getParent() == node->getParent()->getParent()->getLeft()) {
      y = node->getParent()->getParent()->getRight(); // fails on addValue 20 after calling print y->getColour()
      if(y->getColour() == RED) {
        node->getParent()->setColour(BLACK);
        y->setColour(BLACK);
        node->getParent()->getParent()->setColour(RED);
        node = node->getParent()->getParent();
      }
      else {

        if(node = node->getParent()->getRight()){
          node = node->getParent();
          leftRotation(node);
        }
        node->getParent()->setColour(BLACK);
        node->getParent()->getParent()->setColour(RED);
        rightRotation(node->getParent()->getParent());
        node = node->getParent();
      }
    }
    else {
      y = node->getParent()->getParent()->getLeft();
      if(y->getColour() == RED) {
        node->getParent()->setColour(BLACK);
        y->setColour(BLACK);
        node->getParent()->getParent()->setColour(RED);
        node = node->getParent()->getParent();
      }
      else {
        if(node = node->getParent()->getLeft()){
          node = node->getParent();
          rightRotation(node);
        }
        node->getParent()->setColour(BLACK);
        node->getParent()->getParent()->setColour(RED);
        leftRotation(node->getParent()->getParent());
        node = node->getParent();
      }
    }
  }
  root->setColour(BLACK);
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

void Tree::leftRotation(Node* x) {
  // invalid rotation
  if(x->getRight() == nil)
    return;
  Node* y = x->getRight();
  if(y->getLeft() == nil)
    x->setRight(nil);
  else{
    x->setRight(y->getLeft());
    y->getLeft()->setParent(x);
  }
  y->setParent(x->getParent());
  if(x->getParent() == nil)
    root = y;
  else if(x == x->getParent()->getLeft()) //
    x->getParent()->setLeft(y);
  else
    x->getParent()->setRight(y);
  y->setLeft(x);
  x->setParent(y);
}

void Tree::rightRotation(Node* x) {
  // invalid rotation
  if(x->getLeft() == nil)
    return;
  Node* y = x->getLeft();
  if(y->getRight() == nil)
    x->setLeft(nil);
  else{
    x->setLeft(y->getRight());
    y->getRight()->setParent(x);
  }
  y->setParent(x->getParent());
  if(x->getParent() == nil)
    root = y;
  else if(x == x->getParent()->getRight()) //
    x->getParent()->setRight(y);
  else
    x->getParent()->setLeft(y);
  y->setRight(x);
  x->setParent(y);
}

Node* Tree::findNode(int k) {
  return findNode(root,k);
}

Node* Tree::findNode(Node* x,int k) {
  if(x->getData() == k) // If at correct node
    return x;
  if (k < x->getData()) {
    if(x->getLeft() == nil)
      return nil; // If node doesn't exist
    return findNode(x->getLeft(), k);
  } else {
    if(x->getRight() == nil)
      return nil; // If node doesn't exist
    return findNode(x->getRight(), k);
  }
}

void Tree::walk() {
  print(root,1);
  cout << "\n\n________________________________________________________________________\n\n";
}

void Tree::print(Node *x, int space) {
  // Base case
  if (x == nil)
    return;
  int COUNT = 1;
  if(COUNT == -1)
    COUNT = 1;
  space += COUNT;

  // Process right child first
  print(x->getRight(), space);

  // Print current node after space
  // count
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << "   ";
  char colour_;
  if(x->getColour() == 1)
    colour_ = 'B';
  else
    colour_ = 'R';
  cout << x->getData() << "(" << colour_ << ")" << endl;

  // Process left child
  print(x->getLeft(), space);
}
