#include <stdio.h>
#include <vector>
#include <string>
#include "vcat.h"

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom) {
    
    // copy the top picture
    std::vector<std::string> ret = top;
    
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

