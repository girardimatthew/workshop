#include <stdio.h>
#include <vector>
#include <string>
#include "vcat.h"

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
    
    // copy the top picture
    vector<string> ret = top;
    
    // copy entire bottom picture
//    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
//        ret.push_back(*it);
//    }
    // or just
    // ret.insert(ret.end(), bottom.begin(), bottom.end());

    // general solution:
    // copy all of the elements of bottom and append them to the end of ret.
    copy(bottom.begin(), bottom.end(), back_inserter(ret));
    
    return ret;
}

