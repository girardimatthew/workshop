/*
    write program that produce its output sorted by occurrence count.
    That is, the output should group all the words that occur once,
    followed by those that occur twice, and so on.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::string;      using std::vector;
using std::map;         using std::max;
using std::cin;
using std::cout;
using std::endl;

void print_new_line() {
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int max_occur = 0;
    string s;
    map<string, int> counters; // store each word and an associated counter
    map<int, vector<string> > occurrence;
    
    // read the input, keeping track of each word and how often we see it
    while (cin >> s) {
        ++counters[s];
        max_occur = max(max_occur, counters[s]);
    }

    // write the words and associated counts
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
    // create new map based on occurrence count
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        occurrence[it->second].push_back(it->first);
    }

    print_new_line();
    // output sorted by occurence count
    for (map<int, vector<string> >::const_iterator it = occurrence.begin(); it != occurrence.end(); ++it) {
        cout << it->first << ": ";
        for (vector<string>::const_iterator vit = it->second.begin(); vit != it->second.end(); ++vit) {
            cout << *vit << " ";
        }
        cout << endl;
    }

    print_new_line();
    return 0;
}

// output should be
/*
    1: word, word, word
    2: word, word
    3: word
*/