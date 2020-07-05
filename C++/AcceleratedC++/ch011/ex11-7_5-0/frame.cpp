#include <stdio.h>
#include "frame.h"
#include <string>

using std::string;

Vec<string> frame(const Vec<string>& v) {
    
    Vec<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an asterisk and a space
    for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}
