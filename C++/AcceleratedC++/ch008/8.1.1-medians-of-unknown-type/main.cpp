#include <vector>
#include <iostream>
#include <string>

#include "median.h"

using std::vector;
using std::string;

int main(int argc, const char * argv[]) {
    // int
    vector<int> vi = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    int med_i = median(vi);
    std::cout << med_i << std::endl;
    // double
    vector<double> vd = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    double med_d = median(vd);
    std::cout << med_d << std::endl;
    // char
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    std::cout << median(vc) << std::endl;
}