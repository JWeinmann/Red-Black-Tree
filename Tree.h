#ifndef TREE_H
#define TREE_H

enum colour {RED, BLACK, DOUBLEBLACK};

struct Node{
    int data;
    int colour;
    Node *left, *right, *parent;
    explicit Node(int);
};

class Tree{

    public:
        Tree();
        virtual ~Tree(){};
        void addValue(int);




    private:
        Node* root;
        Node* nil;

};

#endif // TREE_H
