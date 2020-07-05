#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 

using std::vector;      using std::endl;
using std::string;
using std::max;
using std::cout;

template <class T>
T max_t(const T& left, const T& right) {
    return left > right ? left : right;
}

int main(int argc, const char * argv[]) {
    
    string name = "Hello C++ !";
    // using int as type of maxlen, the program won't compile.
    //int maxlen = 0;
    string::size_type maxlen = 0;
    maxlen = max(maxlen, name.size());

    string::size_type max_t_len = 42;
    max_t_len = max_t(max_t_len, name.size());
    cout << maxlen << ", " <<  max_t_len << endl;
}