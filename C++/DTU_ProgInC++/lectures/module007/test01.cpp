#include <iostream>
#include "vector2d.h"
 
using namespace std;
 
int main() {
     
     
    v2d v1(3,0);
    v2d v2(0,4);
    v2d v3(3,2);
    v2d v4(v2);
     
    cout << "Pythagoras holds on perpendicular triangles:\n";
    cout << "a=" << v1.length();
    cout << " b=" << v2.length();
     
    v2d v5=v1+ v2 * (-1);
     
    cout << " c=" << v5.length() << endl;
     
    cout << "...but not on non-perpendicular triangles:\n";
    cout << "a=" << v3.length();
    cout << " b=" << v4.length();
     
    v5=v3+ v4 * (-1);
     
    cout << " c=" << v5.length() << endl;
}