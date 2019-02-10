#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct Node{
 //private:
public:
    int data;
    int colour;
    Node *left, *right, *parent;
 public:
    explicit Node(int);
    Node();
    ~Node(){};
    void setData(int);
    void setLeft(Node*);
    void setRight(Node*);
    void setParent(Node*);
    void setColour(int);
    int getData();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    int getColour();
};

class Tree{

    public:
        Tree();
        virtual ~Tree(){};
        void addValue(int);
        void insertFix(Node*);
        void setLeaf(Node*); // point children to nil
        Node* successor(Node*); // return successor of given node
        Node* predecessor(Node*);
        void leftRotation(Node*);
        void rightRotation(Node*);
        Node* findNode(int);
        Node* findNode(Node*,int);
        void walk();
        void print(Node*,int);

    private:
        Node* root;
        Node* nil; // nil parent only matters within specific methods and only for the duration of that method

};

#endif // TREE_H
