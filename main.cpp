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
    cout << "now add 5\n\n\n";
    t.addValue(5);
    t.walk();
    cout << "now add 3\n\n\n";
    t.addValue(3);
    t.walk();
    cout << "now add 23\n\n\n";
    t.addValue(23);
    t.walk();
    cout << "now add 33\n\n\n";
    t.addValue(33);
    t.walk();
    cout << "now add 31\n\n\n";
    t.addValue(31);
    t.walk();
    cout << "now add 20\n\n\n";
    t.addValue(20);
    t.walk();
    cout << "now add 19\n\n\n";
    t.addValue(19);
    t.walk();
    cout << "now add 43\n\n\n";
    t.addValue(43);
    t.walk();
    cout << "now add 50\n\n\n";
    t.addValue(50);
    t.walk();
    cout << "now add 40\n\n\n";
    t.addValue(40);
    t.walk();
    cout << "nowadd19\n\n\n";
    t.addValue(1);
    t.walk();
    cout << "nowadd19\n\n\n";
    t.addValue(2);
    t.walk();
    cout << "here: " << t.findNode(33)->getData();
    t.leftRotation(t.findNode(43));
    t.walk();
    t.rightRotation(t.findNode(20));
    t.walk();
    return 0;
}
