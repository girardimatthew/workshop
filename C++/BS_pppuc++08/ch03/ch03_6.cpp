// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03 
// 3.6 - Composite assignment operators 

// count repeated words

#include <iostream>

using namespace std;

int main() {
	int num_of_words = 0;
	string previous = "";
	string current;
	while (cin>>current) {
		++num_of_words;
		if (previous==current){
			cout << "word number " << num_of_words << " repeated: " << current << '\n';
		}
		previous = current;
	}
}