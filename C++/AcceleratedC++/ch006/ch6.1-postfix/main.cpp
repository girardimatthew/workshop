#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char * argv[]) {

    int it = 0;
    int begin = 1;
    std::cout << "it: " << it << ", begin: " << begin << std::endl;
    it = begin++;
    std::cout << "it: " << it << ", begin: " << begin << std::endl;

    std::cout << std::endl;
    int *outP = &it;
    int *beginP = &begin;
    std::cout << "outP: " << *outP << ", beginP: " << *beginP << std::endl;
    *outP = (*beginP)++;
    std::cout << "outP: " << *outP << ", beginP: " << *beginP << std::endl;
    (*outP)++;
    std::cout << "outP: " << *outP << ", beginP: " << *beginP << std::endl;
    (*beginP)++;
    std::cout << "outP: " << *outP << ", beginP: " << *beginP << std::endl;
    *outP = (*beginP)++;
    (*outP)++;
    std::cout << "outP: " << *outP << ", beginP: " << *beginP << std::endl;
        
    return 0;
}
