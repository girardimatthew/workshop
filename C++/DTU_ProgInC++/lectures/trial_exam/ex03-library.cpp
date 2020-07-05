#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
Dictionary::Dictionary(void){
    // Put your code here
    words.resize(2);
    synonyms.resize(2);
}

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    words[0][u] = v;
    words[1][v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(int lang, string u){
	if (lang < 0 || lang > 1) return "";
    return words[lang][u];
}

// Exercise 3(c)
void Dictionary::insert_synonym(int lang, string u,
                                     string v){
    // Put your code here
    if (lang < 0 || lang > 1) return;
	synonyms[lang][u].insert(v);
	synonyms[lang][v].insert(u);
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(int lang, string u){
    // Put your code here
    set<string> A;
    if (lang < 0 || lang > 1) return A;
    else return synonyms[lang][u];

}

// Exercise 3(e)
set<string> Dictionary::translate(int lang, string u){
    // Put your code here  
    set<string> A;
    if (lang < 0 || lang > 1) return A;
    if(words[lang].find(u) != words[lang].end()){
        A.insert(words[lang][u]);
        for (auto v : get_synonyms((lang+1)%2,words[lang][u])) A.insert(v);
        for (auto v : get_synonyms(lang,u)){
            A.insert(words[lang][v]);
            for (auto w : get_synonyms((lang+1)%2,words[lang][v])) A.insert(w);
        }
    }
    return A;
}

