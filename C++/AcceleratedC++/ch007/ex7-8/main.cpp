#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "words.h"
#include "furls.h"

using std::string;      using std::endl;
using std::map;         using std::vector;
using std::cin;         using std::istream;
using std::cout;

string get_string_for_size(bool more_than_one_line) {
    return more_than_one_line ? "line(s): " : "line   : ";
}

int longest_string(map<string, vector<int> > ret) {
    int longest = 0;
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        if (it->first.size() >= longest)
            longest = it->first.size();
    }
    return longest;
}

int main(int argc, const char * argv[]) {
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin, find_urls);
    // get the longest string
    int longest_s = longest_string(ret);
    // write the result
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        // determine which output text to use;
        string text = get_string_for_size(it->second.size() > 1);
        // determine the space between the word and the text
        string space = string(longest_s - it->first.size(),' ');
        // write the word
        cout << it->first << space << " occurs on " << text;
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