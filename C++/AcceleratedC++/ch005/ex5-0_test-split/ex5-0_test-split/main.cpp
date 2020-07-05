//
//  main.cpp
//  ex5-0_strings
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "split.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    string s;
    
    // read and split each line of input;
    while (getline(cin, s)) {
        vector<string> v = split(s);

        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i) {
            cout << v[i] << endl;
        }
    }

// compare the split function with the following
    while (cin >> s)
        cout << s << endl;
    
    return 0;
}
