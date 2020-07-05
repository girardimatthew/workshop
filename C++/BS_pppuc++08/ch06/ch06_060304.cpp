// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 6.3.4
// Using tokens
// *********************************************************************************

#include <iostream>
#include <vector>
#include "../std_lib_facilities_v2.h"

using namespace std;

class Token {
public:
	char kind;
	double value;
	Token(char ch)
		:kind(ch), value(0) {}
	Token(char ch, double val) 
		:kind(ch), value(val) {}
};

// Token get_token();
// vector<Token> tok;

int main() {
	Token t1('+');
	Token t2('8',11.5);

	cout << "Token t1: (" << t1.kind << ", " << t1.value << ")\n";
	cout << "Token t2: (" << t2.kind << ", " << t2.value << ")\n";
}