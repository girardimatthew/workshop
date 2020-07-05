#include <iostream>
#include <string>

int main() {
    int r = 1;
    int rows = 0;
    // a bool used as a number behaves as 1 if it is true and 0 it it is false.
    std::string result = std::to_string((r == rows) - 1);
    std::cout << "Result: " + result << std::endl;

    return 0;
}