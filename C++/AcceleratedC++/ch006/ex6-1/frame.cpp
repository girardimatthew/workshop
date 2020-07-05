#include <stdio.h>
#include <vector>
#include <string>
#include "width.h"

std::vector<std::string> frame(const std::vector<std::string>& v) {
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');
    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        ret.push_back("* " + *iter + std::string(maxlen - iter->size(), ' ') + " *");
    }    
    // write the bottom border
    ret.push_back(border);
    return ret;
}
// OR
// vector<string> frame(const vector<string>& v) {
//     vector<string> ret;
//     string::size_type maxlen = width(v);
//     string border(maxlen + 4, '*');
//     vector<string>::const_iterator iter = v.begin();

//     ret.push_back(border);

//     while (iter != v.end())  {
//         ret.push_back("* " + *iter++ + string(maxlen - iter->size(), ' ') + " *");
//         }

//     ret.push_back(border);
//     return ret;
// }
