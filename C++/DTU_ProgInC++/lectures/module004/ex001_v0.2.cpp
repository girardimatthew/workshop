// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod04
// version 002
// Matteo Girardi
// *********************************************************************************
// Bag 1
// *********************************************************************************

#include <iostream>
using namespace std;

const string add="add";
const string del="del";
const string qry="qry";
const string quit="quit";


typedef struct {
	int x;
	char isThere;
}set;

#define l 50
int nval(0);
bool diff(false);
set element[l];

set display() {
	for (int i=0; i<nval; ++i) {
		cout << element[i].x << ", " << element[i].isThere << endl;
	}
	cout << endl;
};

// compute intpu command (add, del, qry)
set compute(string cmd, int value) {
	diff = false;
	if (cmd==add && nval<1) {
		element[nval].x=value;
		element[nval].isThere='T';
		++nval;
	}
	else if (cmd==add && nval>=1) {
		for (int i=0; i<nval; ++i) {
			if (element[i].x!=value) {
				diff=true;
			}
		}
		if (diff) { 
			element[nval].x=value;
			element[nval].isThere='T';
			++nval;
		}
	}
	else if (cmd==del) {
		for (int i=0; i<nval; ++i) {
			if (element[i].x==value) {
				element[i].isThere='F';
			}
		}
	}
	else if (cmd==qry) {
		if (nval<1) { cout << element[nval].isThere; }
		for (int i=0; i<nval; ++i) {
			if (element[i].x==value) {
				cout << element[i].isThere;
			}
		}
	}
};

// initialize the set of elements to 0 and False
set init() {
	for (int i=0; i<l; ++i) {
		element[i].x = 0;
		element[i].isThere = 'F';
	}
};

int main() {
	string cmd = " ";
	int value = 0;
	init();

	while (cin>>cmd && cmd!=quit) {		
		cin >> value;
		compute(cmd, value);
	}
	cout << endl;
	// display();
	// cout << endl;
	return 0;
}
