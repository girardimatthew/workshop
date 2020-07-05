// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 7
// P. 126
// *********************************************************************
// Modify the "mini calculator" from exercise 5 to accept (just)
// single-digit numbers written as either digits or spelled out.
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<string> numb_str(2,"zero");
	string oper = "+";
	int val1 = 0;
	int val2 = 0;

	cout << "Please enter two values (just single-digit numbers as either digits or spelled out) : " << endl;

	for(int i=0; i<numb_str.size(); ++i){
		cin >> numb_str[i];
	}
	
	if(numb_str[0] == "zero" || numb_str[0] == "0"){
		val1 = 0;
	}
	else if(numb_str[0] == "one" || numb_str[0] == "1"){
		val1 = 1;
	}
	else if(numb_str[0] == "two" || numb_str[0] == "2"){
		val1 = 2;
	}
	else if(numb_str[0] == "three" || numb_str[0] == "3"){
		val1 = 3;
	}
	else if(numb_str[0] == "four" || numb_str[0] == "4"){
		val1 = 4;
	}
	else if(numb_str[0] == "five" || numb_str[0] == "5"){
		val1 = 5;
	}
	else if(numb_str[0] == "six" || numb_str[0] == "6"){
		val1 = 6;
	}
	else if(numb_str[0] == "seven" || numb_str[0] == "7"){
		val1 = 7;
	}
	else if(numb_str[0] == "eight" || numb_str[0] == "8"){
		val1 = 8;
	}
	else if(numb_str[0] == "nine" || numb_str[0] == "9"){
		val1 = 9;
	}
	else{
		cout << "Bad input.\n";
	}

	if(numb_str[1] == "zero" || numb_str[1] == "0"){
		val2 = 0;
	}
	else if(numb_str[1] == "one" || numb_str[1] == "1"){
		val2 = 1;
	}
	else if(numb_str[1] == "two" || numb_str[1] == "2"){
		val2 = 2;
	}
	else if(numb_str[1] == "three" || numb_str[1] == "3"){
		val2 = 3;
	}
	else if(numb_str[1] == "four" || numb_str[1] == "4"){
		val2 = 4;
	}
	else if(numb_str[1] == "five" || numb_str[1] == "5"){
		val2 = 5;
	}
	else if(numb_str[1] == "six" || numb_str[1] == "6"){
		val2 = 6;
	}
	else if(numb_str[1] == "seven" || numb_str[1] == "7"){
		val2 = 7;
	}
	else if(numb_str[1] == "eight" || numb_str[1] == "8"){
		val2 = 8;
	}
	else if(numb_str[1] == "nine" || numb_str[1] == "9"){
		val2 = 9;
	}
	else{
		cout << "Bad input.\n";
	}

	cout << "Please, enter an operator: " << endl;
	cin >> oper;

	cout << "-------------------------------------------------------------------------------------\n";
	if (oper == "+"){
		cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << endl;
	} 
	else if (oper == "-") {
		cout << "The substraction of " << val1 << " and " << val2 << " is " << val1 - val2 << endl;
	}
	else if (oper == "*") {
		cout << "The multiplication of " << val1 << " and " << val2 << " is " << val1 * val2 << endl;
	}
	else if  (oper == "/") {
		cout << "The division of " << val1 << " and " << val2 << " is " << val1 / val2 << endl;
	}
	else if (oper == "%") {
		cout << "The module of " << val1 << " and " << val2 << " is " << val1 % val2 << endl;
	}
	else 
		cout << "Wrong operator" << endl;
}