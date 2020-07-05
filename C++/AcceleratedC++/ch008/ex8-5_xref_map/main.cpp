#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "split.h"
#include "crossref.h"

using std::string;      using std::endl;
using std::map;         using std::vector;
using std::cin;         using std::istream;
using std::cout;        using std::max;
using std::pair;

int main() {
    string::size_type maxlen = 0;      // the length of the longest name
    map<string, vector<int> > ret;
    xref(cin, split, inserter(ret, ret.begin()));
    // find longest name
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        maxlen = max(maxlen, it->first.size());
    }
    // write the result
    cout << "=== Words occur on line(s) ===" << endl;
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        // write the word
        cout << it->first 
             << ": "
             << string(maxlen + 1 - it->first.size(), ' ')
             <<  " [ ";
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        // write the first line number
        cout << *line_it;
        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }
        // write a new line to separate each word from the next
        cout << " ]" << endl;
    }
    return 0;
}