// *********************************************************************************
// Programming in C++ 
// Exercise 002 - mod05
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string wdset;
	char cmd;
	vector<char> dsetA;
	vector<char> dsetB;
	int n = 0;

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
	
	for (int i=0; i<(dsetA.size()+dsetB.size()); ++i) {
		if (dsetA.size() > 0 && n <= (dsetA.size()-1)) {
			cout << dsetA[n] << " ";
		}
		if (dsetB.size() > 0 && n <= (dsetB.size()-1)) {
			cout << dsetB[n] << " ";
		}
		++n;
	}
	cout << endl;
	return 0;
}


// TEST
// a 3 b 2 b 1 a 1 a 4 b 2
// a 3 a 2 b 1
// b 6 b 5 a 8