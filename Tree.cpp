#include "Tree.h"
#include <iostream>
using namespace std;

// In RB trees, every node is added as RED and properties are fixed in insertFix()
Node::Node(int data_) : data(data_), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}

Tree::Tree() : root(nullptr), nil(nullptr) {
  nil = new Node();
}
