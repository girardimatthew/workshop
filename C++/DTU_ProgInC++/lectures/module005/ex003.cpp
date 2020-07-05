// *********************************************************************************
// Programming in C++ 
// Exercise 003 - mod05
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string wdset;
	char cmd;
	vector<int> dsetA;
	vector<int> dsetB;
	int scPr= 0;
	int maxSize = 0;

	getline(cin, wdset);

	for (int i=0; i<wdset.size(); ++i) {
		if (wdset[i] == 'a' || wdset[i] == 'b') {
			cmd = wdset[i];
		}
		else if (wdset[i] == ' ')
			;
		else 
			if (cmd=='a') {
				dsetA.push_back((int)wdset[i]-48);
			}
			else
				dsetB.push_back((int)wdset[i]-48);
	}
	if (dsetA.size() >= dsetB.size()) { maxSize = dsetA.size(); }
	else { maxSize = dsetB.size(); }
	
	for (int i=0; i<maxSize; ++i) {
		scPr += dsetA[i] * dsetB[i];
	}
	cout << scPr << endl;
	return 0;
}


// TEST
// a 3 b 2 b 1 a 1 a 4 b 2
// a 3 a 2 b 2 a 5 b 3
// b 0 b 1 b 3 a 4 a 7 a 4 b 6