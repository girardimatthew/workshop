// Accelerated C++ 
// Ex: 5-9
// Write a program to write the words in the input
// that do not contain any uppercase letters followed 
// by the words that contain one or more uppercase letters.

#include <iostream>
#include <vector>
#include <string>
#include "split.h"

bool containsUppercase(string str) {
    for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if(!islower(*it)) { return true; }
    }
    return false;
}

bool hasUppercaseLetters(string str) {
    return !std::all_of(str.begin(), str.end(), islower);
}

void printVector(const vector<string>& v) {
    for (std::vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    std::cout << std::endl;
}

void prettyPrint(const vector<string>& v) {
    for (std::vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << "\t - " << *iter << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {

    std::string s;

    vector<string> stringsWithUppercases;
    vector<string> stringsWithLowercases;

    while (std::getline(std::cin, s)) {
        vector<string> inputWords = split(s);

        for (std::vector<string>::const_iterator iter = inputWords.begin(); iter != inputWords.end(); ++iter) {
            if (containsUppercase(*iter)) { 
                stringsWithUppercases.push_back(*iter);
            } else {
                stringsWithLowercases.push_back(*iter);
            }
        }
    }

    std::cout << "\n========================================================== " << std::endl;
    std::cout << "Words that do not contain any uppercase letters: " << std::endl;
    prettyPrint(stringsWithLowercases);

    std::cout << "Words that contain one or more uppercase letters: " << std::endl;
    prettyPrint(stringsWithUppercases);

    // TODO: 
    // compare performance of 
    // containsUppercase and hasUppercaseLetters

    return 0;
}
