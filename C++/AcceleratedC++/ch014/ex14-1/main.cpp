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

#include <sstream>
using std::stringstream;

#include "../lib/Student_info.h"
#include "../lib/Str.h"

int main() {
    stringstream ss1("Jan 15 20 30 40");
    stringstream ss2("Jan 80 90 70 50");

    Ptr<Core> p1 = new Core(ss1);
    Ptr<Core> p2 = new Core(ss2);

    cout << "Is " << p1->name() << " == " << p2->name() << " ? " << (compare_Ptr_Cores(p1, p2) == 0) << endl;
}