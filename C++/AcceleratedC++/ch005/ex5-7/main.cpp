// Accelerated C++ 
// Ex: 5-7 

#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include "frame.h"
#include "hcat.h"
#include "vcat.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {

    vector<string> v;
    vector<string> vframe = frame(v);

    for (vector<string>::const_iterator iter = vframe.begin(); iter != vframe.end(); ++iter) {
        cout << *iter << endl;
    }

    // OR
    // vector<string>::const_iterator iter = vframe.begin();
    // while (iter != vframe.end()) {
    //     cout << *iter++ << endl;
    // }
    
    return 0;
}
