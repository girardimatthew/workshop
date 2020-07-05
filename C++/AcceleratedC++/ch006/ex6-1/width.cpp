#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>& v) {
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        maxlen = std::max(maxlen, iter->size());
    }
    return maxlen;
}
// OR 
// std::string::size_type width(const std::vector<std::string>& v) {
//     std::string::size_type maxlen = 0;
//     typedef std::vector<std::string>::const_iterator iter;
//     iter it = v.begin();

//     while (it != v.end())
//         maxlen = max(maxlen, it++->size());
//     return maxlen;
// }
