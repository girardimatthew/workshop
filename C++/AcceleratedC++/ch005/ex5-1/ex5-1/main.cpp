//
//  main.cpp
//  ex5-1
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s) {
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}

std::vector<int> countWhiteSpaces(std::string input) {

    vector<int> indexesOfWhiteSpaces;
    int nSpaces = 0;
    unsigned int i = 0;

    if (input.empty()) { return indexesOfWhiteSpaces; }

    // Skip over spaces at the beginning of the word
    while(isspace(input.at(i)))
        ++i;

    for (; i < input.length(); ++i) {
        if(isspace(input.at(i))) {
            indexesOfWhiteSpaces.push_back(i);

            // Skip over duplicate spaces & if a NULL character is found, we're at the end of the string
            while(isspace(input.at(i++))) { /* no-op */ }
        }
    }

    return indexesOfWhiteSpaces;
}

struct Rotation {
    std::string phrase;
    std::string rest;
};

bool compare(const Rotation& x, const Rotation& y) {
    // convert string to lower case for comparison
    std::string tmpX = x.phrase;
    std::string tmpY = y.phrase;
    transform(tmpX.begin(), tmpX.end(), tmpX.begin(), ::tolower); 
    transform(tmpY.begin(), tmpY.end(), tmpY.begin(), ::tolower); 
    return  tmpX < tmpY;
}

int main(int argc, const char * argv[]) {

    string inputPhrase;
    vector<int> whiteSpacesPosition;
    vector<Rotation> rotations;
    int longest = 0;

    while (getline(cin, inputPhrase)) {

        string trimmedLine = trim(inputPhrase); // remove whitespaces at start and end.
        whiteSpacesPosition = countWhiteSpaces(trimmedLine); 
        Rotation input = { .phrase = trimmedLine, .rest = "" };
        rotations.push_back(input);

        for (vector<int>::const_iterator iter = whiteSpacesPosition.begin(); iter != whiteSpacesPosition.end(); ++iter) {
            int whiteSpacePosition = *iter;

            std::string afterWhitespace = inputPhrase.substr(whiteSpacePosition+1);
            std::string beforeWhitespace = inputPhrase.substr(0, whiteSpacePosition);
            // save the longest string, in order to have a pretty print
            if (beforeWhitespace.size() > longest) { longest = beforeWhitespace.size(); }

            Rotation r = { .phrase = afterWhitespace, .rest = beforeWhitespace };
            rotations.push_back(r);
        }
    }

    sort(rotations.begin(), rotations.end(), compare);

    cout << endl;

    for (vector<Rotation>::const_iterator iter = rotations.begin(); iter != rotations.end(); ++iter) {
        int diff = longest - iter->rest.size();
        cout << std::string(diff, ' ');
        cout << iter->rest << "    " << iter->phrase << endl;
    }
}