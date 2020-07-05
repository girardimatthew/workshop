#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>

int main() {
    const size_t NDim = 3;
    double coords[NDim];
    *coords = 1.5;

    for(size_t i = 0; i != NDim; ++i) {
        cout << coords[i] << " ";
    }
    cout << endl;
    // a pointer is a random access iterator
    *(coords + 1) = 42.0;
    *(coords + 2) = 11.0;
    for(size_t i = 0; i != NDim; ++i) {
        cout << coords[i] << " ";
    }
    cout << endl;
    // copy contents of coords into a vector
    //vector<double> v;
    //copy(coords, coords + NDim, back_inserter(v));
    // or even shorter
    vector<double> v(coords, coords + NDim);

    double *p = coords;
    double *q = (p + 2);
    cout << p << ", " << *p << endl;
    cout << p << ", " << p[1] << endl;
    cout << q << ", " << *q << endl;
    ptrdiff_t s = p - q;
    cout << s << endl; // -2 ??

    // 
    const int month_lengths[] = {
        31, 28, 31, 30, 31, 30, // we will deal elsewhere with leap years 31, 31, 30, 31, 30, 31
    };
    cout << month_lengths << endl; // address
    cout << *month_lengths << endl; // address
    cout << month_lengths[1] << endl;
    cout << *(month_lengths + 5) << endl;
    //cout << *(month_lengths + 6) << endl; // 

    return 0;
}