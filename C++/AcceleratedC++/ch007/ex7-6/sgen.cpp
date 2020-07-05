#include "sgen.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using std::domain_error;
using std::logic_error;

// read a grammar from a given input stream
Grammar read_grammar(std::istream& in) {

    Grammar ret;
    string line;
    // read the input
    while (getline(in, line)) {
        // split the input into words
        vector<string> entry = split(line);
        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }

    // **** some cave-man debug
    // for (Grammar::const_iterator i = ret.begin(); i != ret.end(); ++i) {
    //     std::cout << i->first << std::endl;
    //     for (Rule_collection::const_iterator ric = i->second.begin(); ric != i->second.end(); ++ric) {
    //         for (Rule::const_iterator ri = ric->begin(); ri != ric->end(); ++ri) {
    //             std::cout << "\t" << *ri << std::endl;
    //         }
    //     }
    // }

    return ret;
}

bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand id out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}

void gen_aux(const Grammar& g, 
             const string& word, 
             vector<string>& ret, 
             vector<string>& tokens) {

    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        // from which we select one at random
        const Rule& r = c[nrand(c.size())];
        // push rule's tokens onto stack of tokens
        // (in reverse order, because we're pushing and popping from the back)
        for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
            tokens.push_back(*i);
    }
}

vector<string> gen_sentence(const Grammar& g) {
    vector<string> sentence;
    vector<string> tokens;
    tokens.push_back("<sentence>");

    while (!tokens.empty()) {
        string token = tokens.back();
        tokens.pop_back();
        gen_aux(g, token, sentence, tokens);
    }

    return sentence;
}