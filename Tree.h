#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct Node{
 private:
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
        void setLeaf(Node*); // point children to nil
        

    private:
        Node* root;
        Node* nil;

};

#endif // TREE_H
