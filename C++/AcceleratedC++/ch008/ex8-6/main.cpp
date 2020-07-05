#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::copy;

#include <utility>
using std::pair;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {

    map<int, string> m = { 
        { 1, "Hello World!" },
        { 3, "Den Fede Pingvin" }
    };
    
    vector<pair<int, string>> x = {
        { 1, "Cards Against Humanity." },
        { 3, "J.R.R Tolkien" }
    };
    
    // container that supports output iterator operations, push_back and that holds <int,string> pairs
    copy(m.begin(), m.end(), back_inserter(x));

    for(vector<pair<int, string>>::const_iterator iter = x.begin(); iter != x.end(); ++iter) {
        cout << iter->first << ", " << iter->second << endl;
    }

    // map doesn't support push_back so back_inserter is an invalid operation
    //copy(x.begin(), x.end(), back_inserter(m));

    return 0;
}
