// Write a program to count how many times each distinct word appears in its input.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    // ask for words
    cout << "Please enter a series of words "
            "followed by end-of-file: ";
    
    // the words and the words vector
    string aWord;
    vector<string> words;
    vector<int> wordsCounter;
    // 
    bool found;
    
    // invariant:
    while (cin >> aWord) {
        found = false;
        
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == aWord) {
                found = true;
                ++wordsCounter[i];
            }
        }

        if (!found) {
            words.push_back(aWord);
            wordsCounter.push_back(1);
        }
    }
    
    //
    for (int i = 0; i < words.size(); ++i) {
        cout << "[" << i << "]" << words[i] << ": " << wordsCounter[i] << endl;
    }
    cout << endl;
    return 0;
}