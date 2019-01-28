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
        Node* insertNode(Node *, Node*);
        void insertFix(Node *);
        void deleteValue(int);
        Node* findNode(int);
        Node* findNode(Node*, int);
        Node* findMin(Node*);
        Node* findMax(Node*);
        void deleteFix(Node *);
        int getColour(Node *);
        void transplant(Node*, Node*);
        void setColour(Node *, int);
        void leftRotation(Node *);
        void rightRotation(Node *);
        void walk();
        void print(Node*, int);






    private:
        Node* root;

};

#endif // TREE_H
