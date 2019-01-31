#include <iostream>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "Tree.h"

using namespace std;

int main()
{
    Tree t;
    Node n;
    Node *nodeptr = new Node();
    cout << "here: " << nodeptr->getData();
    nodeptr->setData(5);
    cout << "\nhere: " << nodeptr->getData();
    return 0;
}
