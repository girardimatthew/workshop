// *********************************************************************************
// Programming in C++ 
// Exercise 001 - mod09
// Reverse: Write a program that reverses a sequence of integers, as provided in the standard input
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {	
	if (s.empty())
		return s;
	return reverse(s.substr(1)) + s[0];
}

int main() {
	string s;
	getline(cin, s);
	cout << reverse(s) << endl;

	return 0;
}