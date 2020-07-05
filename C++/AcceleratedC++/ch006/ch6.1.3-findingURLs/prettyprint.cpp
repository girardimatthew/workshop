#include "prettyprint.h"
#include <vector>
#include <iostream>

void printv(const std::vector<std::string>& v, bool withNewLine) {
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        if (withNewLine) { std::cout << *iter << std::endl; }
        else { std::cout << *iter << " "; }
    }
    std::cout << std::endl;
}