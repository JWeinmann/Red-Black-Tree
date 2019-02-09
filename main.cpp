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
    t.addValue(5);
    t.addValue(3);
    t.addValue(23);
    t.addValue(33);
    t.addValue(31);
    t.addValue(20);
    t.addValue(19);
    t.addValue(43);
    t.addValue(50);
    t.addValue(40);
    t.addValue(1);
    t.addValue(2);
    t.walk();
    cout << "here: " << t.findNode(33)->getData();
    t.leftRotation(t.findNode(43));
    t.walk();
    t.rightRotation(t.findNode(20));
    t.walk();
    return 0;
}
