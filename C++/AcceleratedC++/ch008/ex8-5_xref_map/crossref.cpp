#include <vector>
#include <string>
#include <map>
#include <iostream>

using std::vector;      using std::istream;
using std::string;      using std::back_insert_iterator;
using std::map;

template <class Out>
Out xref(
    istream& in, 
    void find_words(const string&, back_insert_iterator<vector<string> > ),
    Out os
    ) {
    
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read the next line
    while (getline(in, line)) {
        ++line_number;
        // break the input line into words
        vector<string> words;
        find_words(line, back_inserter(words));
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            // avoid occurrence of line
            if (find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end())
                ret[*it].push_back(line_number);
        }
    }

    // write results to output iterator
    copy(ret.begin(), ret.end(), os);

    return os;
}