#include <iostream>
#include <vector>
#include <string>
#include "split.h"

int main(int argc, const char * argv[]) {
    
    std::string s;
    
    // read and split each line of input;
    while (std::getline(std::cin, s)) {
        vector<string> v = split(s);

        // write each word in v
        std::cout << "\nInput words:" << std::endl;
        for (vector<string>::size_type i = 0; i != v.size(); ++i) {
            std::cout << "\t - " << v[i] << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
