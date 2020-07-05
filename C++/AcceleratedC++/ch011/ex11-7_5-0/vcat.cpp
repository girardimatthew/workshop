#include <stdio.h>
#include "vcat.h"
#include <string>

Vec<string> vcat(const Vec<string>& top, const Vec<string>& bottom) {
    
    // copy the top picture
    Vec<string> ret = top;
    
    // copy entire bottom picture
   for (Vec<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
       ret.push_back(*it);
   }
    // or just
    //ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

