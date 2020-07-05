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

#include "Str.h"
#include "Student_info.h"

using std::streamsize;
using std::domain_error;
using std::sort;

int main() {
    // convert 10 to double and use the converted value to initialize d
    double d = 10;
    double d2;
    // convert 10 to double and assign the converted value to d2
    d2 = 10;
    // construct s. explicitly ask for constructor that takes a const char*
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

    vector<Student_info> vs;
    vs.push_back(Student_info(10, 10, "John"));
    vs.push_back(Student_info(11, 11, "Jack"));
    vs.push_back(Student_info(42, 42, "Tom"));

    cout << vs[0].name() << endl;

    double vsd = 0;
    for (int i = 0; i != vs.size(); ++i) {
        d += vs[i];
    }
    cout << "Average grade: " << d / vs.size() << endl;

    return 0;
}