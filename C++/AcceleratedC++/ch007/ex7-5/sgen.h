#ifndef sgen_h
#define sgen_h

#include <map>
#include <list>
#include "split.h"

typedef std::vector<string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in);
std::list<string> gen_sentence(const Grammar& g);

#endif /* sgen_h */