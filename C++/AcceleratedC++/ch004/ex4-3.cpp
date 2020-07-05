// ex4.3
// Write a program to calculate the squares of int values up to 100.
// The program should write two columns: The first lists the value;
// the second contains the square of the value. Use setw to manage the 
// output so that the values line up in columns.
#include <iomanip>
#include <cmath>
#include <iostream>
#include "square.h"

using std::cout;
using std::endl;
using std::setw;

int get_width(int n) {
  return log10(n) + 1;
}

int main() {
    
    int upperLimit = 1000;

    for(int i = 0; i <= upperLimit; ++i) {
        cout << setw(get_width(upperLimit)) 
             << i 
             << setw(get_width(square(upperLimit)) + 1) 
             << square(i) 
             << endl;
    }
}
