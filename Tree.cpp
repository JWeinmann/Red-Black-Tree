#include "Tree.h"
#include <iostream>
using namespace std;

Node::Node() : data(-1), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}

// In RB trees, every node is added as RED and properties are fixed in insertFix()
Node::Node(int data_) : data(data_), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}

void Node::setData(int key) {
  data = key;
  return;
}

void Node::setLeft(Node* node) {
  left = node;
  return;
}

void Node::setRight(Node* node) {
  right = node;
  return;
}

void Node::setParent(Node* node) {
  parent = node;
  return;
}

void Node::setColour(int newColour) {
  colour = newColour;
  return;
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

Tree::Tree() : root(nullptr), nil(nullptr) {
  Node* node = new Node();
  nil = node;
  nil->setColour(BLACK);
}
