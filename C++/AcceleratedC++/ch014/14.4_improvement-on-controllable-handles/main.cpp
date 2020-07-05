#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include "Student_info.h"
#include "Str.h"

int main() {
    Str s("Hello Str!");
    // initialize t. copy constructor
    Str t = "hello";
    // assign a new value to s. expression statement
    s = "hello";
    cout << s[0] << endl;

    Str name = "World";
    Str greeting = "Hello, " + name + "!";
    cout << greeting << endl;

    Str temp1("Hello, ");
    Str temp2 = temp1 + name;
    Str temp3("!");
    Str greeting2 = temp2 + temp3;
    cout << greeting2 << endl;
}