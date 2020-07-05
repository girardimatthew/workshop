#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
 
//#include "split.h" 
// g++ main.o split.o -o 8.4-using-iterators-for-flexibility
// duplicate symbol 'not_space(char)' in:
//     main.o
//     split.o
// duplicate symbol 'space(char)' in:
//     main.o
//     split.o
// ld: 2 duplicate symbols for architecture x86_64
// clang: error: linker command failed with exit code 1 (use -v to see invocation)

using std::vector;              using std::endl;
using std::string;              using std::cout;
using std::cin;                 using std::istream_iterator;
using std::copy;                using std::back_inserter;
using std::ostream_iterator;

// true if the argument is whitespace, false otherwise
bool space(char c) {
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
    return !isspace(c);
}

template <class Out> 
void split(const std::string& str, Out os) {
    
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        // find end of next word
        iter j = find_if(i, str.end(), space);
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = std::string(i, j);
        i = j;
    }
}

int main(int argc, const char * argv[]) {

    cout << "Enter some numbers (cmd+d to stop):" << endl;
    string s;
    while (getline(cin, s))
        split(s, ostream_iterator<string>(cout, "\n"));
    return 0;
}