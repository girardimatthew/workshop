#include <vector>
#include <iostream>
#include <string>

#include "median.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

template <class Ran>
void print(Ran begin, Ran end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // int
    vector<int> vi = { 2, 9, 5, 4, 6, 5, 2, 1, 1 };
    print(vi.begin(), vi.end());
    int med_i = median<vector<int>::iterator, int>(vi.begin(), vi.end());
    cout << med_i << endl;
    print(vi.begin(), vi.end());
    // double
    vector<double> vd = { 2.0, 9.2, 5.3, 4.2, 6.9, 5.8, 2.8, 1.9, 0.1 };
    print(vd.begin(), vd.end());
    double med_d = median<vector<double>::iterator, double>(vd.begin(), vd.end());
    cout << med_d << endl;
    print(vd.begin(), vd.end());
    // char
    vector<char> vc = { 'h', 'e', 'l', 'l', 'o' }; 
    cout << median<vector<char>::iterator, char>(vc.begin(), vc.end()) << endl;

    const int numbers[] = { 2, 9, 5, 8 }; 
    const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
    cout << *numbers << endl;
    cout << *(numbers + (ngrades - 1)) << endl;
}