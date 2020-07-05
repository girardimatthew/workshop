// A quine is a computer program which takes no input and produces a copy of its own source code as its only output.

#include <iostream>
#include <string>

int main() {
    std::string code1 = R"(#include <iostream>int main() { )";

    std::cout << code1 << std::endl;;
}