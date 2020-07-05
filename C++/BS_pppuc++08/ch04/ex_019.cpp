// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 19
// P. 128
// *********************************************************************************
// Write a program where you first enter a set of name-and-value pairs
// such as Joe 17 and Barbara 22. For each pair, add the name to a vector
// called names and the number to a vector called scores (in corresponidng position).
// Terminate input by the line No more.
// Check that each name is unique and terminate with an error message if a name 
// is entered twice. Write out all the (name, score) pairs, one per line.
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

int main() {
	string inscore;
	string inname;
	bool valid=true;
	vector<string> names;
	vector<double> scores;

	cout << "Please enter a name-and-value pairs such as 'John 17'. Terminate with 'No more'.\n";
	// store the input name-and-values and check if the names appears twice
	while (cin>>inname>>inscore && !(inname=="No") && !(inscore=="more")) {
		if (isdigit(inscore[0]) || isdigit(inscore[1])) {
			valid=true;
			for (int i=0; i<names.size(); ++i) {
				if (inname==names[i]) {
					valid=false;
				}
			}
			if (valid) {
				names.push_back(inname);
				scores.push_back(stod(inscore));
			}
			else {
				cout << "Error: input name " << inname << " already inserted.\nPlease input a new name.\n";
			}
		}
		else {
			cout << "ERROR!. " << inscore << " is not a value.\nQuitting the program.\n";
			exit(0);
		}
	}
	// print out all the pairs
	cout << "----------------------------------------------------\n";
	cout << "name, score.\n";
	for (int i=0; i<names.size(); ++i) {
		cout << "   - (" << names[i] << ", " << scores[i] << ")" << endl;
	}
}