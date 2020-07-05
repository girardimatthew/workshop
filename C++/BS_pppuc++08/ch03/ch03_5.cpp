// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03 
// 3.5 - Assignment and initialization 

// detects adjacent repeated words in a sequence of words.

#include <iostream>

using namespace std;

int main() {

	string previous = "";
	string current;
	int count = 0;

	while (cin>>current) {
		if (previous == current) {
			cout << "repeated word: " << current << '\n';
			count += 1;
		}
		previous = current;
	}
	cout << "Total repeated word: " << count << '\n';

}