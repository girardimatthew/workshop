#include <iostream>
#include <vector>
#include <cmath>
#include "shapes.h"
 
using namespace std;
 
int main(void){
 
    Rectangle u(2,3);
    Square v(2);
    Circle w(1);

    // .. and print
    cout << "Rectangle: " << u.height() << ", " << u.width() << endl;
    cout << "Square: " << v.height() << ", " << v.width() << endl;
    cout << "Circle: " << w.height() << ", " << w.width() << endl;
 
    // Print all areas
    cout << "Areas..." << endl;
    cout << round(u.area()) << endl;
    cout << round(v.area()) << endl;
    cout << round(w.area()) << endl;
 
    // Print all perimeters
    cout << "Perimeters..." << endl;
    cout << round(u.perimeter()) << endl;
    cout << round(v.perimeter()) << endl;
    cout << round(w.perimeter()) << endl;

    // rotate shapes
    u.rotate();
    v.rotate();
    w.rotate();

    // .. and print
    cout << "Rectangle: " << u.height() << ", " << u.width() << endl;
    cout << "Square: " << v.height() << ", " << v.width() << endl;
    cout << "Circle: " << w.height() << ", " << w.width() << endl;

    return 0;
 
}

// Expected output
// Areas...
// 6
// 4
// 3
// Perimeters...
// 10
// 8
// 6