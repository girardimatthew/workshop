#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "words.h"

using std::string;      using std::endl;
using std::map;         using std::vector;
using std::cin;         using std::istream;
using std::cout;

int main(int argc, const char * argv[]) {
    
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);

    // write the result
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        // write the word
        cout << it->first << " occurs on line(s): ";
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
        cout << endl;
    }
    return 0;
}
