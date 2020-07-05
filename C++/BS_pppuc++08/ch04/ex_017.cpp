// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 17
// P. 128
// *********************************************************************************
// Write a program that finds the min, max and the mode of a sequence of strings.
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	string sin, prevs;
	int howmanyof=1, maxstrings=2;
	vector<string> wseq;
	vector<string> smode;
	vector<string> longest;
	vector<string> shortest;
	vector<int> length;

	cout << "Write a program that finds the min, max and the mode of a sequence of strings.\n";
	cout << "Please enter a sequence of digits (to exit |): \n";
	
	// storing the input sequence of strings into a vector
	while (cin>>sin) {
		if (sin=="|") {
			break;
		}
		else {
			wseq.push_back(sin);
			length.push_back(sin.length());
		}
	}
	// just checking the input sequence of strings
	// cout << "------------------------------------------------------------\n";
	// cout << "Here is the input sequence of strings\n";
	// for (int i=0; i<wseq.size(); ++i) {
	// 	cout << "[" << i << "]: " << wseq[i] << ", " << length[i] << endl;
	// }
	cout << "------------------------------------------------------------\n";
	cout << wseq.size() << " strings found." << endl;
	// finding the max string or strings
	for (int i=0; i<wseq.size(); ++i) {
		if (i<1) {
			longest.push_back(wseq[i]);
			shortest.push_back(wseq[i]);
		}
		else {
			if (wseq[i].length()>longest.back().length()) {
				longest.clear();
				longest.push_back(wseq[i]);
			}
			else if (wseq[i].length()==longest.back().length() && wseq[i]!=longest.back()) {
				longest.push_back(wseq[i]);
			}
			if (wseq[i].length()<shortest.back().length()) {
				shortest.clear();
				shortest.push_back(wseq[i]);
			}
			else if (wseq[i].length()==shortest.back().length() && wseq[i]!=shortest.back()) {
				shortest.push_back(wseq[i]);
			}
		}
	}
	// just printing out the longest string (one or more if equal)
	if (longest.size()>1) {
		cout << "The longest strings are: ";
		for (int i=0; i<longest.size(); ++i) {
			cout << longest[i] << ", ";
		}
		cout << endl;
	}
	else {
		cout << "The longest string is: " << longest.back() << endl;
	}
	// just printing out the shortest string (one or more if equal)
	if (shortest.size()>1) {
		cout << "The shortest strings are: ";
		for (int i=0; i<shortest.size(); ++i) {
			cout << shortest[i] << ", ";
		}
		cout << endl;
	}
	else {
		cout << "The shortest string is: " << shortest.back() << endl;
	}

	// sorting the sequence of strings
	sort(wseq.begin(), wseq.end());
	// finding the mode (one or more)
	for (int i=0; i<wseq.size(); ++i) {
		if (prevs==wseq[i]) {
			++howmanyof;
			if (howmanyof>maxstrings) {
				maxstrings=howmanyof;
				smode.clear();
				smode.push_back(wseq[i]);
			}
			else if (howmanyof==maxstrings) {
				smode.push_back(wseq[i]);
			}
		}
		else {
			howmanyof=1;
		}
		prevs=wseq[i];
	}
	// just printing out what has been found... 
	if (smode.size()>1) {
		cout << "The modes are: ";
		for (int i=0; i<smode.size(); ++i) {
			cout << smode[i] << ", ";
		}
		cout << endl;
	}
	else if (smode.size()==1) {
		cout << "The mode is: " << smode.back() << endl;
	}
	else {
		cout << "No mode found.\n" << endl;
	}
}