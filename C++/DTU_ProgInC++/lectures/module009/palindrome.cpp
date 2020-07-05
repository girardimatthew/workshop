// *********************************************************************************
// Programming in C++ 
// Exercise 002 - mod09
// Palindrome: Write a program that decides whether a sequence of integers is a 
// palindrome, i.e. if reading the sequence from right to left results in the very same sequence.
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isPal(vector<int> &iv, int start, int end) {
    if (start >= end)   
        return true;
    if (iv[start] != iv[end])
        return false;
    return isPal(iv, ++start, --end);   
}

int main() {
	vector<int> ivec;
  	string str;
	getline(cin, str);
	istringstream sstr(str);
	int n = 0;
	while(sstr >> n)
	  ivec.push_back(n);

	int start = 0;
	int end = ivec.size()-1;
	bool ans = isPal(ivec,start,end);
	if (ans)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

// TESTS
// 1 2 3 4 5 4 3 2 1	yes	
// 13 33 31				no
// 13					yes
// 23 23				yes