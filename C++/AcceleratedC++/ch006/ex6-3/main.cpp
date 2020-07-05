#include <vector>
#include <iostream>
#include <string>
#include "prettyprint.h"

int main(int argc, const char * argv[]) {
    std::vector<int> u(10, 100);
    std::vector<int> v;
    printv(u, false);
    // Segmentation fault: 11
    // copy(u.begin(), u.end(), v.begin());
}