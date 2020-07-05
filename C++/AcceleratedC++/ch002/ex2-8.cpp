#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    
    // write a program to generate the product
    // of the numbers in the range [1, 10)
    for (int i = 1; i != 10; ++i) {
        cout << i << "*" << i << " = " << i*i << endl;
    }
}