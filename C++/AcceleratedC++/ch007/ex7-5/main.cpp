#include <iostream>
#include <string>
#include <list>

#include "sgen.h"

using std::string;
using std::cin;
using std::cout; 
using std::endl;
using std::list;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    // generate the sentece
    list<string> sentence = gen_sentence(read_grammar(cin));
    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }
    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    return 0;
}
