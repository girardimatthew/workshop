#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;              using std::endl;
using std::string;              using std::cout;
using std::cin;                 using std::istream_iterator;
using std::copy;                using std::back_inserter;
using std::ostream_iterator;

template <class T> T zero() { return 0; }

int main(int argc, const char * argv[]) {
    // double x = zero(); // won't compile
    // it needs to be zero<double>() !
    double x = zero<double>();
    cout << x << endl;
    return 0;
}