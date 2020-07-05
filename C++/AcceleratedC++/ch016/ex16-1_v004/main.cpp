// A quine is a computer program which takes no input and produces a copy of its own source code as its only output.

#include <iostream>
#include <string>

int main() {
    std::string code1 = R"(
#include <iostream>
int main() {
)";
    std::string code2 = R"(
    std::cout << code1
              << "    std::string code1 = R\"(" << code1 << ")\";\n"
              << "    std::string code2 = R\"(" << code2 << ")\";\n"
              << code2;
}
)";

    std::cout << code1
              << "    std::string code1 = R\"(" << code1 << ")\";\n"
              << "    std::string code2 = R\"(" << code2 << ")\";\n"
              << code2;
}