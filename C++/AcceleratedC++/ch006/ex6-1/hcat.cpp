#include <stdio.h>
#include <vector>
#include <string>
#include "hcat.h"
#include "width.h"

std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right) {
    
    std::vector<std::string> ret;
    // add 1 to leave a space between pictures
    std::string::size_type width1 = width(left) + 1;
    // indices to look at elements from left and right respectively
    typedef std::vector<std::string>::const_iterator iter;
    iter leftIter = left.begin();
    iter rightIter = right.begin();
    
    // continue until we've seen all rows from both pictures
    while (leftIter != left.end() || rightIter != right.end()) {
        // construct new string to hold characters from both pictures
        std::string s;
        // copy a row from the left-hand side, if there is one
        if (leftIter != left.end()) { s = *leftIter++; }
        // pad to full width
        s += std::string(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (rightIter != right.end()) { s += *rightIter++; }
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
