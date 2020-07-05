#pragma once

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

// adapter to attach map<string, vector<int>> output iterator to std out
template <class T, class charT = char, class traits = std::char_traits<charT> >
class my_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    std::basic_ostream<charT, traits>* out_stream;
    const charT* delim;

    public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef std::basic_ostream<charT, traits> ostream_type;
        my_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
        my_ostream_iterator(ostream_type& s, const charT* delimiter) : out_stream(&s), delim(delimiter) { }
        my_ostream_iterator(const my_ostream_iterator<T, charT, traits>& x) : out_stream(x.out_stream), delim(x.delim) {}
        ~my_ostream_iterator() {}

    // print pair<string, vector<int>> to std out
    my_ostream_iterator<T, charT, traits>& operator=(const T& value) {
        *out_stream << value.first << ": ";
        for (int i = 0; i != value.second.size(); ++i)
            *out_stream << value.second[i] << delim;
        
        *out_stream << std::endl;
        return *this;
    }

    my_ostream_iterator<T, charT, traits>& operator*() { return *this; }
    my_ostream_iterator<T, charT, traits>& operator++() { return *this; }
    my_ostream_iterator<T, charT, traits>& operator++(int) { return *this; }
};