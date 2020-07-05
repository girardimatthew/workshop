#include <stdio.h>
#include <string>
#include "width.h"

using std::string;
using std::max;

string::size_type width(const Vec<string>& v) {
    
    string::size_type maxlen = 0;
    for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    
    return maxlen;
}
