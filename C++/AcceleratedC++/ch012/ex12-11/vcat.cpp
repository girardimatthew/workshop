#include <stdio.h>
#include "vcat.h"
#include <vector>
using std::vector;

#include "../Str/Str_c.h"

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom) {
    
    // copy the top picture
    vector<Str> ret = top;
    
    // copy entire bottom picture
//    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
//        ret.push_back(*it);
//    }
    // or just
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

