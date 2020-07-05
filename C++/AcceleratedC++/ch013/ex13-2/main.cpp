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
    cout << "--- new Core ---" << endl;
    Core* p1 = new Core;
    cout << "--- new Grad ---" << endl;
    Core* p2 = new Grad;

    cout << "--- Core s1 ---" << endl;
    Core s1;
    cout << "--- Grad s2 ---" << endl;
    Grad s2;

    cout << "--- p1->grade() ---" << endl;
    // crash! libc++abi.dylib: terminating with uncaught exception of type std::domain_error: student has done no homework
    //p1->grade();
    cout << "--- p1->name() ---" << endl;
    p1->name();

    cout << "--- p2->grade() ---" << endl;
    // libc++abi.dylib: terminating with uncaught exception of type std::domain_error: student has done no homework
    //p2->grade();
    cout << "--- p2->name() ---" << endl;
    p2->name();

    cout << "--- s1.grade(); ---" << endl;
    // libc++abi.dylib: terminating with uncaught exception of type std::domain_error: student has done no homework
    //s1.grade();
    cout << "--- s1.name(); ---" << endl;
    s1.name();

    cout << "--- s2.name(); ---" << endl;
    
    s2.name();
    cout << "--- s2.grade(); ---" << endl;
    // libc++abi.dylib: terminating with uncaught exception of type std::domain_error: student has done no homework
    //s2.grade();

    delete p1;
    delete p2;

    return 0;
}