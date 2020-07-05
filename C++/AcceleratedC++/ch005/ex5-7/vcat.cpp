// Accelerated C++ 
// Ex: 5-7 

#include <stdio.h>
#include "vcat.h"
#include <vector>
#include <string>

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    
    // copy the top picture
    vector<string> ret = top;
    
    // copy entire bottom picture
//    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
//        ret.push_back(*it);
//    }
    // or just
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

