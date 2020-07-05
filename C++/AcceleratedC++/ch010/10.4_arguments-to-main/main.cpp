#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstddef>
#include <cstring>

using std::string;

int main(int argc, char** argv) {
    // if there are arguments, write them
    if (argc > 1) {
        int i;      // declare i outside the for because we need it after the loop
        for (i = 1; i < argc - 1; ++i) {    // write all but the last entry 
            cout << argv[i] << " ";
        }
        cout << argv[i] << endl;    // write the last entry but not a space
    }
    cout << argv[1][0] << endl;
    return 0;
}