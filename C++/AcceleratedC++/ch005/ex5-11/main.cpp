// Accelerated C++ 
// Ex: 5-11
// Write a program to determine whether a word has any ascenders or descenders
// Extend that program to find the longest word in the dictionary
// that has neither ascenders nor descenders
// ascenders: b, d, f, h, k, l, t
// descenders: g, j, p, q, y

#include <iostream>
#include <vector>
#include <string>
#include "split.h"

struct Word {
    const string w;
    const bool hasAscenders;
    const bool hasDescenders;
};

void printVector(const std::vector<std::string>& v, bool withNewLine) {
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        if (withNewLine) { std::cout << *iter << std::endl; }
        else { std::cout << *iter << " "; }
    }
    std::cout << std::endl;
}

bool hasDiscenders(const std::string& s) {
    for (std::string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
        const char c = ::tolower(*iter);
        if (c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y') {
            return true;
        }
    } 
    return false;
}

bool hasAscenders(const std::string& s) {
    for (std::string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
        const char c = ::tolower(*iter);
        if (c == 'b' || c == 'd' || c == 'f' || c == 'h' || c == 'k' || c == 'l' || c == 't') {
            return true;
        }
    } 
    return false;
}

std::vector<Word> getWords(const std::vector<std::string>& v) {
    std::vector<Word> words;
    for (std::vector<std::string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {

        Word w = { *iter, hasAscenders(*iter), hasDiscenders(*iter) };
        words.push_back(w);
    }
    return words;
}

std::string findLongestWordWithout(const std::vector<Word>& w) {
    std::string longest;
    int size = 0;
    for (std::vector<Word>::const_iterator iter = w.begin(); iter != w.end(); ++iter) {
        if (!(*iter).hasAscenders && !(*iter).hasDescenders && (*iter).w.size() >= size) {
            size = (*iter).w.size();
            longest = (*iter).w;
        }
    }
    return longest;
}


int main(int argc, const char * argv[]) {

    const std::vector<std::string> inputWords = {
        "Hello", "World!", "racecar", "Copenhagen", "Madam",
        "civic", "dog", "radar", "level", "America", "rotor", "sand", "kayak",
        "ABBA", "sequential", "Otto", "library", "algorithms", "saippuakivikauppias", 
        "tattarrattat", "implementation", "processing", "bool", "deal", "Florida",
        "joke", "Joe", "quest", "year", "aeiou", "wruioaszxcvnm",
        "bdfhkl", "gjpqy"
    };
    const std::vector<Word> words = getWords(inputWords);


    std::cout << "\n========================= Input words ================================= " << std::endl;
    printVector(inputWords, false);

    std::cout << "\n================== Words with ascenders and descenders ================ " << std::endl;
    for (std::vector<Word>::const_iterator iter = words.begin(); iter != words.end(); ++iter) {

        std::cout 
            << (*iter).w << "\n" 
            << "\t hasAscenders: " << ((*iter).hasAscenders ? "✅" : "❌") 
            << "\t hasDescenders: " << ((*iter).hasDescenders ? "✅" : "❌") 
            << std::endl;
    }

    std::cout << "\n=========== Longest word without ascenders and descenders ============= " << std::endl;
    std::string longestWordWithout = findLongestWordWithout(words);
    std::cout << longestWordWithout << std::endl;

    return 0;
}
