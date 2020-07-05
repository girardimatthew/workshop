//
//  vcat.cpp
//  ex5-0_strings
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

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

