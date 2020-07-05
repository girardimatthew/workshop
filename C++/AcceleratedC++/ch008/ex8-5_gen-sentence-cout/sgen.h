#pragma once

#include <map>
#include "split.h"

using std::map;
using std::vector;
using std::string;
using std::domain_error;
using std::logic_error;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

int nrand(int);
bool bracketed(const std::string&);
Grammar read_grammar(std::istream& in);

template <class Out>
Out gen_aux(const Grammar& g, const string& word, Out o) {
    
    if (!bracketed(word)) {
        *o = word;
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);

        if (it == g.end())
            throw logic_error("empty rule");
        
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        // from which we select one at ranfom
        const Rule& r = c[nrand(c.size())];
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            gen_aux(g, *i, o);
        }
    }

    return o;
}

template <class Out>
Out gen_sentence(const Grammar& g, Out o) {
    gen_aux(g, "<sentence>", o);

    return o;
}

// read a grammar from a given input stream
Grammar read_grammar(std::istream& in) {

    Grammar ret;
    string line;
    // read the input
    while (getline(in, line)) {
        // split the input into words
        vector<string> entry;
        split(line, back_inserter(entry));

        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0, n)
int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand id out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}
