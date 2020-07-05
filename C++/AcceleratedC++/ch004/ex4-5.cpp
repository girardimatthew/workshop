// ex4-5
// Write a function that reads words from an input stream and stores them in a vector. 
// Use that function both to write programs that count the number of words in the input
// and to count how many times each word occurred.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string>::size_type vec_str_sz;

struct Word_info {
    string word;
    int occurrences;
};

void print(const vector<string>& record) {
    cout << endl;
    for(vec_str_sz i = 0; i < record.size(); ++i) {
        cout << record[i] << endl;
    }
}

istream& readWords(istream& in, vector<string>& words) {
    
    if (in) {
        // get rid of previous content
        words.clear();

        // read input and store it
        string word;
        while (in >> word)
            words.push_back(word);

        // clear the stream
        in.clear();
    }

    return in;
}

void occurrence(const vector<string>& record) {
    vector<string> recordCopy;
    vector<string> occurrence;
    vector<int> counter;

    recordCopy = record;
    sort(recordCopy.begin(), recordCopy.end());
    
    string prev = "";
    for(vec_str_sz i = 0; i < recordCopy.size(); ++i) {
        if (recordCopy[i] == prev) {
            ++counter.back();
        } else {
            string word = recordCopy[i];
            occurrence.push_back(word);
            counter.push_back(1);
        }
        prev = recordCopy[i];
    }

    for(vec_str_sz i = 0; i < occurrence.size(); ++i) {
        cout << occurrence[i]
             << ": "
             << counter[i]
             << endl;
    }

}

int main() {
    
    vector<string> words;
    readWords(cin, words);

    cout << "The number of words is: " 
         << words.size() 
         << endl;
    
    occurrence(words);
}