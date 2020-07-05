#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <cstdlib>
#include <time.h>

#include "sgen.h"

using std::string;          using std::list;
using std::cin;             using std:: back_inserter;
using std::cout;            using std::endl;

int main() {
    srand(time(NULL));

    // generate the sentece
    list<string> sentence;
    gen_sentence(read_grammar(cin), back_inserter(sentence));

    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();

    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }

    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    
    cout << endl;

    return 0;
}


// int main(int argc, const char * argv[]) {
//     srand(time(NULL));
//     // generate the sentece
//     vector<string> sentence = gen_sentence(read_grammar(cin));
//     // write the first word, if any
//     vector<string>::const_iterator it = sentence.begin();
//     if (!sentence.empty()) {
//         cout << *it;
//         ++it;
//     }
//     // write the rest of the words, each preceded by a space
//     while (it != sentence.end()) {
//         cout << " " << *it;
//         ++it;
//     }
//     cout << endl;
//     return 0;
// }
