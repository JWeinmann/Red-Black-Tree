# Red-Black-Tree - started November 2018
##Jack Weinmann 

## Implementation of a Red-Black Tree in C++ (still incomplete)

This is an implementation of the Red-Black Tree (RBT) data structure in C++. 

An RBT is a type of Binary Searth Tree (BST). A BST is a container designed to be a more efficient (in certain situations) than arrays, vectors, singly or doubly-linked lists, etc in memory. A BST has certain basic operations at a minimum (insertion, deletion, search). The first node is known as the root and has no parent, and each node from then on down has two children nodes. Consequently, on average, these operations take time proportional to the logarithm of the number of stored elements (n). 
A Red-Black Tree is a type of Binary Search Tree designed to be self-balancing. Being a BST, the running time of most operations (insert, delete, search, etc.) is dependent on its height, so the idea behind being self-balancing is to achieve faster operation times by constraining the maximum possible height given a certain number of nodes.

The Red-Black Tree data structure achieves the self-balancing property by giving each node a colour and imposing a set of rules regarding the permissible distribution of these colours. Like a BST, each node  has a key and keeps track its parent and two children, but in a Red-Black Tree an extra bit is  used to store its colour: either RED or BLACK (the colour DOUBLE BLACK may be used when deleting nodes to help you when an issue exists, but if the process of deleting a node is followed properly this is unnecessary). This information is used in conjunction with the following set of rules, carefully chosen so as to maximize the efficiency of restructuring or recolouring:

   1. Every node is either RED or BLACK.

   2. The root is BLACK.

   3. Every leaf (NIL) is BLACK.

   4. If a node is RED, then both its children are BLACK.

   5. For each node, all simple paths from the node to descendant leaves contain the same number of BLACK nodes.

For a traditional BST, the cost of operations such as search, insert, and delete, is O(h). A heavily skewed BST can have a height equal to the number of nodes it consists of, which means those operations can have a cost of O(n). The height of a Red-Black Tree is at most 2log(n+1), and thus the operational cost of these same operations on a Red-Black Tree is at most O(logn).

Read-only operations (search, find minimum, find maximum) on Red-Black Trees are performed the same as they are on an ordinary BST, but insertion and deletion require modification to maintain Red-Black Tree property adherence. 



## INSERTION

Below, x denotes the node being inserted, z denotes the node being examined. 

Red-Black Tree insertion begins very much the same as in BST. The key of a node being inserted, x, is compared to the key of the root, z. If x.key is less than z.key, the algorithm moves on to the z.left, otherwise it moves onto z.right. In each case respectively, the new z becomes z.left or z.right, and the algorithm performs the same operation as was done on the root. This continues until the new z is NIL. At this point, x.parent=z.parent, z=x, x.left=NIL, x.right=NIL, and x.colour=RED.

********* add explanation of insertFixUp, delete, deleteFixUp, etc. 
