#include <vector>
#include <iostream>
#include <string>
#include "prettyprint.h"

void solution01() {
    std::vector<int> u(10, 100);
    std::vector<int> v;
    printv(u, false);
    copy(u.begin(), u.end(), back_inserter(v));
    printv(v, false);
}

void solution02() {
    std::vector<int> u(10, 100);
    std::vector<int> v(u);
    printv(u, false);
    printv(v, false);
}

void solution03() {
    std::vector<int> u(10, 100);
    std::vector<int> v = u;
    printv(u, false);
    printv(v, false);
}

void solution04() {
    std::vector<int> u(10, 100);
    std::vector<int> v(u.size());
    copy(u.begin(), u.end(), v.begin());
    printv(u, false);
    printv(v, false);
}

void solution05() {
    std::vector<int> u(10, 100);
    std::vector<int> v;

    std::vector<int>::const_iterator iter = u.begin();
    while (iter != u.end())
        v.push_back(*iter++);
    
    printv(u, false);
    printv(v, false);
}

int main(int argc, const char * argv[]) {
    solution01();
    solution02();
    solution03();
    solution04();
    solution05();
}