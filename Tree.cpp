#include "Tree.h"
#include <iostream>
using namespace std;

// In RB trees, every node is added as RED and properties are fixed in insertFix()
Node::Node(int data_) : data(data_), colour(RED), left(nullptr), right(nullptr),
                        parent(nullptr) {}

Tree::Tree() : root(nullptr) {}

void Tree::addValue(int nodeData) {
  Node *node = new Node(nodeData);
  root = insertNode(root, node);
  insertFix(node);
}

// insertNode works its way down the tree and inserts new node in place of leaf
Node* Tree::insertNode(Node* currentNode, Node* node) {
  // Check if at leaf node or tree is empty
  if (currentNode == nullptr)
    return node;

  if(node->data < currentNode->data) {
    currentNode->left = insertNode(currentNode->left, node);
    currentNode->left->parent = currentNode;
  } else if (node->data > currentNode->data) {
    currentNode->right = insertNode(currentNode->right, node);
    currentNode->right->parent = currentNode;
  }
  return currentNode;
}

// Restore tree properties
void Tree::insertFix(Node* currentNode) {
  Node* parent = nullptr;
  Node* grandparent = nullptr;
  Node* uncle = nullptr;
  // Check if property 4 is violated, which states that if a node is RED, both
  // children must be BLACK
  while(currentNode != root && getColour(currentNode) == RED && getColour(currentNode->parent) == RED) {
    parent = currentNode->parent;
    grandparent = parent->parent;
    // Left versions of cases 1-3
    if(parent == grandparent->left) {
      uncle = grandparent->right;
      if(getColour(uncle) == RED) { // Case 1
        setColour(uncle, BLACK);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        currentNode = grandparent;
      } else {
        if(currentNode == parent->right) { // Case 2
          currentNode = parent;
          leftRotation(parent);
          parent = currentNode->parent;
        }
        // Case 3
        rightRotation(grandparent);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        currentNode = parent;
      }
    }
    // Right versions of cases 1-3
    else {
      uncle = grandparent->left;
      if(getColour(uncle) == RED) { // Case 1
        setColour(uncle, BLACK);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        currentNode = grandparent;
      } else {
        if(currentNode == parent->left) { // Case 2
          currentNode = parent;
          rightRotation(parent);
          parent = currentNode->parent;
        }
        // Case 3
        leftRotation(grandparent);
        setColour(parent, BLACK);
        setColour(grandparent, RED);
        currentNode = parent;
      }
    }
  }
  setColour(root, BLACK);
}

// Finds node, replaces node data with predecessor data, then deletes predecessor
void Tree::deleteValue(int k) {
  Node* x = findNode(k);
  Node* y = nullptr;
  if(x == nullptr) // No node with data==k exists
    return;
  else {
  if(x->right == nullptr)
    y = x;
  else {
    // RB Tree will use predecessor version of Red-Black Tree deletion
    y = findMin(x->right);
    x->data = y->data;
  }
  deleteFix(y);
  }
}

Node* Tree::findNode(int k) {
  return findNode(root,k);
}

Node* Tree::findNode(Node* x, int k) {
  if(x->data == k)
    return x;
  if (k < x->data) {
    if(x->left == nullptr)
      return nullptr;
    return findNode(x->left, k);
  } else {
    if(x->right == nullptr)
      return nullptr;
    return findNode(x->right, k);
  }
}

Node* Tree::findMin(Node *x) {
  while (x->left!=nullptr)
    x = x->left;
  return x;
}

void Tree::deleteFix(Node* x) {
    //Test if delete was called on a non-existing key
  if (x == nullptr)
    return;

    //Test if x is root
  if (x == root) {
    root = nullptr;
    return;
  }

  if (getColour(x) == RED || getColour(x->left) == RED || getColour(x->right) == RED) {
    Node* child = nullptr;
    if(x->left != nullptr) {
      child = x->left;
    } else {
      child = x->right;
    }
    transplant(x, child);
    setColour(child, BLACK);
    delete (x);
  } else {
    Node* sibling = nullptr;
    Node* parent = nullptr;
    Node* y = x;
    setColour(y, DOUBLEBLACK);

    //While x is not the root and is still DOUBLEBLACK
    while(y != root && getColour(y) == DOUBLEBLACK) {
      parent = y->parent;
      if(y == parent->left) {
        sibling = parent->right;
        //Case 1 - can only result in cases 2,3, or 4
        if(getColour(sibling) == RED) {
          setColour(sibling, BLACK);
          setColour(parent, RED);
          leftRotation(parent);
        } else { //Everything in this else is either case 2, 3, or 4
          //Case 2 - solves DOUBLEBLACK and so while loop won't execute afer case 2
          if(getColour(sibling->left) == BLACK && getColour(sibling->right) == BLACK) {
            setColour(sibling, RED);
            if (getColour(parent) == RED)
              setColour(parent, BLACK);
            else
              setColour(parent, DOUBLEBLACK);
            y = parent;
            //else either case 3 or case 4 apply
          } else {
            //Case 3 applies -- always results in case 4
            if(getColour(sibling->right) == BLACK) {
              setColour(sibling->left, BLACK);
              setColour(sibling, RED);
              rightRotation(sibling);
              sibling = parent->right;
            }
            setColour(sibling, getColour(parent));
            setColour(parent, BLACK);
            setColour(sibling->right, BLACK);
            leftRotation(parent);
            break;
          }
        }
      } else {
        // Symmetrical to first 4 cases
        sibling = parent->left;
        // Case 1
        if(getColour(sibling) == RED) {
          setColour(sibling, BLACK);
          setColour(parent, RED);
          rightRotation(parent);
        } else {
          // Case 2
          if(getColour(sibling->left) == BLACK && getColour(sibling->right) == BLACK) {
            setColour(sibling, RED);
            if (getColour(parent) == RED)
              setColour(parent, BLACK);
            else
              setColour(parent, DOUBLEBLACK);
            y = parent;
          } else {
            // Case 3
            if(getColour(sibling->left) == BLACK) {
              setColour(sibling->right, BLACK);
              setColour(sibling, RED);
              leftRotation(sibling);
              sibling = parent->left;
            }
            setColour(sibling, getColour(parent));
            setColour(parent, BLACK);
            setColour(sibling->left, BLACK);
            rightRotation(parent);
            break;
          }
        }
      }
    }
    if(y == x->parent->left)
      x->parent->left = nullptr;
    else
      x->parent->right = nullptr;
    delete (x);

    setColour(root, BLACK);
  }
}

int Tree::getColour(Node* node) {
  if (node == nullptr)
    return BLACK;
  return node->colour;
}

void Tree::transplant(Node* u, Node* v) {
  if(u==u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
}

void Tree::setColour(Node* node, int colour) {
  if(node == nullptr)
    return;
  node ->colour = colour;
}

void Tree::leftRotation(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if(x->right != nullptr)
    x->right->parent = x;
  y->parent = x->parent;

  if(x->parent == nullptr)
    root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  y->left = x;
  x->parent = y;
}

void Tree::rightRotation(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if(x->left != nullptr)
    x->left->parent = x;
  y->parent = x->parent;

  if(x->parent == nullptr)
    root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;

  y->right = x;
  x->parent = y;
}

void Tree::walk() {
  print(root,1);
}

void Tree::print(Node *x, int space) {
  // Base case
  if (x == nullptr)
    return;
  int COUNT = 1;
  if(COUNT == -1)
    COUNT = 1;
  space += COUNT;

  // Process right child first
  print(x->right, space);

  // Print current node after space
  // count
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << "   ";
  char colour_;
  if(x->colour == 1)
    colour_ = 'B';
  else
    colour_ = 'R';
  cout << x->data << "(" << colour_ << ")" << endl;

  // Process left child
  print(x->left, space);

}
