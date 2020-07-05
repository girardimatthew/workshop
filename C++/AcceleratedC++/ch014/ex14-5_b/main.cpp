#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::find_if;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include <sstream>
using std::stringstream;

#include "../lib/Student_info.h"
#include "../lib/Str.h"

void printVector(const vector<Str>& v) {

    for (vector<Str>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << *iter << endl;
    }

    cout << endl;
}

// true if the argument is whitespace, false otherwise
bool space(char c) {
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
    return !isspace(c);
}

vector<Str> split(const Str& str) {
    typedef Str::const_iterator iter;
    std::vector<Str> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        // find end of next word
        iter j = find_if(i, str.end(), space);
        // copy the characters in [i, j)
        if (i != str.end())
            ret.push_back(Str(i, j));
        i = j;
    }
    return ret;
}

// vector<Str> split(const Str& s) {
    
//     vector<Str> ret;
//     typedef Str::size_type string_size;
//     string_size i = 0;
    
//     // invariant: we have processed characters [original value of i, i)
//     while (i != s.size()) {
//         // ignore leading blanks
//         // invariant: characters in range [original i, current i) are all spaces
//         while (i != s.size() && isspace(s[i]))
//             ++i;
        
//         // find end of next word
//         string_size j = i;
//         // invariant: none of the characters in range [original j, current j) is a space
//         while (j != s.size() && !isspace(s[j]))
//             ++j;
        
//         // if we found some nonwhitespace characters
//         if (i != j) {
//             // copy from s starting at i and taking j - i chars
//             ret.push_back(s.substr(i, j - i));
//             i = j;
//         }
//     }
//     return ret;
// }

Str::size_type width(const vector<Str>& v) {
    
    Str::size_type maxlen = 0;
    for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
        maxlen = std::max(maxlen, v[i].size());
    }
    
    return maxlen;
}

vector<Str> frame(const vector<Str>& v) {
    
    vector<Str> ret;
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an asterisk and a space
    for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + Str(maxlen - v[i].size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right) {
    
    vector<Str> ret;
    
    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<Str>::size_type i = 0, j = 0;
    
    // ex5-8: define s outside the scope of the while?
    Str s;
    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new string to hold characters from both pictures
        // string s;
        // 
        // defining s outside the scope of the while loop
        // won't affect the output since each loop
        // s = left[i++];
        
        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        //std::cout << s << std::endl;
        // pad to full width
        s += Str(width1 - s.size(), ' ');
        //std::cout << s << std::endl;
        
        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
        //std::cout << s << std::endl;
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom) {
    
    // copy the top picture
    vector<Str> ret = top;
    
    // copy entire bottom picture
//    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it) {
//        ret.push_back(*it);
//    }
    // or just
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

int main() {
    
    Str s;
    
    // TODO
    // read and split each line of input;
    // while (getline(cin, s)) {
    // }

    cout << "\n== Hard-coded input ==\n" << endl;
    vector<Str> v1 = { "Hello World!", "test one" };
    vector<Str> v2 = { "The quick brown fox", "jumped over the lazy dogs." };
    vector<Str> h = hcat(v1, v2);
    printVector(h);

    vector<Str> v1_frame = frame(v1);
    vector<Str> v2_frame = frame(v2);
    vector<Str> h_frame = hcat(v1_frame, v2_frame);
    printVector(h_frame);
    vector<Str> v_frame = vcat(v1_frame, v2_frame);
    printVector(v_frame);
    
    return 0;
}
