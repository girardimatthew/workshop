#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>
#include <cstring>

using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

using std::cerr;

// Here is a program that produces, on its standard output
// a copy of the contents of all the files whose names are given as arguments to main:
int main(int argc, char** argv) {
    
    int fail_count = 0;
    // for each file in the input list
    for (int i = 1; i < argc; ++i) {
        ifstream in(argv[i]);
        
        // if it exists, write its contents,
        // otherwise generate an error message
        if (in) {
            string s;
            while (getline(in,s))
                cout << s << endl;
        } else {
            cerr << "cannot open file " << argv[i] << endl;
        }
    }
    return fail_count;
}