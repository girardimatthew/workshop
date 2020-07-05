// ex4.4
// Change your squares program to use double values instead of ints. Use manipulators to manage the
// output so that the values line up in columns.
#include <iomanip>
#include <cmath>
#include <iostream>
#include "square.h"

using std::cout;
using std::endl;
using std::setw;

double get_width(double n) {
  return log10(n) + 1;
}

int main() {
    
    double upperLimit = 100; // or 1000

    for(double i = 0; i <= upperLimit; ++i) {
        cout << setw(get_width(upperLimit)) 
             << i 
             << setw(get_width(square(upperLimit)) + 1) 
             << square(i) 
             << endl;
    }
}
