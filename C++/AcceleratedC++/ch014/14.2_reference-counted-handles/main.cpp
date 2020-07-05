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

int main() {
    Student_info s1(cin);
    Student_info s2 = s1;
    cout << s1.name() << endl;
    cout << s2.name() << endl;
    s2.setName("John");
    cout << s2.name() << endl;
    cout << s1.name() << endl;
}