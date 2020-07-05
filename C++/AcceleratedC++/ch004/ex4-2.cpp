// ex4.2
// Write a program to calculate the squares of int values up to 100.
// The program should write two columns: The first lists the value;
// the second contains the square of the value. Use setw to manage the 
// output so that the values line up in columns.
#include <iomanip>
#include <iostream>
#include "square.h"

using std::cout;
using std::endl;
using std::setw;

int main() {
    
    int upperLimit = 100;

    for(int i = 0; i <= upperLimit; ++i) {
        cout << setw(3) 
             << i 
             << setw(8) 
             << square(i) 
             << endl;
    }
}