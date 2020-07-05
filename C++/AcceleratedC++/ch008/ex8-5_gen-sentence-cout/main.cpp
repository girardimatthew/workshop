#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <time.h>

#include "sgen.h"

using std::string;          using std::vector;
using std::cin;             using std::ostream_iterator;
using std::cout; 
using std::endl;

int main() {
    srand(time(NULL));

    // generate the sentece
    ostream_iterator<string> out_it(cout, " ");
    gen_sentence(read_grammar(cin), out_it);
    
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
