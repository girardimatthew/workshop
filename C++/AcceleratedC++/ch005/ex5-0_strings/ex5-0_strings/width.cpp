//
//  width.cpp
//  ex5-0_strings
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;

string::size_type width(const vector<string>& v) {
    
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    
    return maxlen;
}
