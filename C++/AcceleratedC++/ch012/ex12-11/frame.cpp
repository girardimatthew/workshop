#include <stdio.h>
#include "width.h"
#include <vector>
using std::vector;

#include "../Str/Str_c.h"

vector<Str> frame(const vector<Str>& v) {
    
    vector<Str> ret;
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an asterisk and a space
    for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + Str(maxlen - v[i].size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}
