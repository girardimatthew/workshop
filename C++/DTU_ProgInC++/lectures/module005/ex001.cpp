// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod05
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string wdset;
	char cmd;
	vector<char> dsetA;
	vector<char> dsetB;

	getline(cin, wdset);

	for (int i=0; i<wdset.size(); ++i) {
		if (wdset[i] == 'a' || wdset[i] == 'b') {
			cmd = wdset[i];
		}
		else if (wdset[i] == ' ')
			;
		else 
			if (cmd=='a') {
				dsetA.push_back(wdset[i]);
			}
			else
				dsetB.push_back(wdset[i]);
	}
	sort(dsetA.begin(), dsetA.end());
	sort(dsetB.begin(), dsetB.end());
	for (int i = 0; i < dsetA.size(); ++i) {
		cout << dsetA[i] << " ";
	}
	for (int i = 0; i < dsetB.size(); ++i) {
		cout << dsetB[i] << " ";
	}
	cout << endl;
	return 0;
}


// TEST
// a 3 b 2 b 1 a 1 a 4 b 2
// a 3 a 2 a 3
// b 6 b 5 b 4