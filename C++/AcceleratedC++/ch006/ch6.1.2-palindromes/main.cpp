#include <iostream>
#include <vector>
#include <string>
#include "split.h"

void printVector(const std::vector<std::string>& v, bool withNewLine) {
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        if (withNewLine) { std::cout << *iter << std::endl; }
        else { std::cout << *iter << " "; }
    }
    std::cout << std::endl;
}

bool is_palindrome(const string& s) {
    string copyS = s;
    // convert string to lower case
	std::for_each(copyS.begin(), copyS.end(), [](char & c) {
		c = ::tolower(c);
	});
    return equal(copyS.begin(), copyS.end(), copyS.rbegin());
} 

std::vector<std::string> getPalindromes(const std::vector<std::string>& v) {
    std::vector<std::string> palindromes;
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        if (is_palindrome(*iter)) {
            palindromes.push_back(*iter);
        }
    }
    return palindromes;
}

std::string longest(const std::vector<std::string>& v) {
    int longest = 0;
    std::string longestPalindrome;
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        int size = (*iter).size();
        if (size >= longest) { 
            longest = size;
            longestPalindrome = *iter;
        }
    }
    return longestPalindrome;
}

int main(int argc, const char * argv[]) {

    std::vector<std::string> inputWords = {
        "Hello", "racecar", "Copenhagen", "10801", "Madam",
        "civic", "dog", "RaDaR", "level", "America", "rotor", "sand", "kayak",
        "ABBA", "sequential", "Otto", "library", "91019", "algorithms", "saippuakivikauppias", 
        "tattarrattat", "implementation", "1111", "processing"
    };
    //std::vector<std::string> inputWords = { "Hello", "racecar", "01010101010101010101010101010" };

    std::vector<std::string> palindromes = getPalindromes(inputWords);

    std::cout << "\n========================= Input words ================================= " << std::endl;
    printVector(inputWords, true);

    std::cout << "\n========================= Palindromes ================================= " << std::endl;
    printVector(palindromes, true);

    std::cout << "\n================== Longest palindrome ================================= " << std::endl;
    std::cout << longest(palindromes) << std::endl;

    return 0;
}
