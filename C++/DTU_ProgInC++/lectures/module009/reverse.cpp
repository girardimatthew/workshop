// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod09
// Reverse: Write a program that reverses a sequence of integers, as provided in the standard input
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void reverse (vector<int> iv, int size) {
	if (size==0) 
		return;
	else {
		cout << iv[size-1] << " ";
		reverse(iv,size-1);
	}
}

int main() {
	vector<int> ivec;

  	string str;
	getline(cin, str);
	istringstream sstr(str);
	int n = 0;
	while(sstr >> n)
	  ivec.push_back(n);

	reverse(ivec, ivec.size());
	cout << endl;
}

// ----------------------------
// TESTS
// 1 2 3 4 5 6 7 8 9 10
// 2 2 1 1 2 2 3 3
// 1
// ----------------------------
// OUTPUT
// 10 9 8 7 6 5 4 3 2 1
// 3 3 2 2 1 1 2 2
// 1

