// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 6
// P. 126
// *********************************************************************
// Make a vector holding the ten string values "zero", "one", ....
// "nine". Use that in a program that converts a digit to its 
// corresponding spelled-out value;
// e.g. the input 7 gives the output seven.
// Have the same program. using the same input loop, 
// convert spelled-out numbers into their digit form;
// e.g. the input seven gives the input 7
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> numb_str(10);
	numb_str[0] = "zero";
	numb_str[1] = "one";
	numb_str[2] = "two";
	numb_str[3] = "three";
	numb_str[4] = "four";
	numb_str[5] = "five";
	numb_str[6] = "six";
	numb_str[7] = "seven";
	numb_str[8] = "eight";
	numb_str[9] = "nine";
	vector<int> str_numb(10, 0);
	for(int i = 0; i<str_numb.size(); ++i){
		str_numb[i] = i;
	}
	string ntemp = "0";


	cout << "--------------------------------------------------------\n";
	cout << "The vector holds the following strings: \n";
	for(int i = 0; i < numb_str.size(); ++i){
		cout << "element[" << i << "]: " << numb_str[i] << endl;
	}

	cout << "--------------------------------------------------------\n";
	cout << "Convert digit to spelled-out.\n";
	while(cin>>ntemp){
		if(ntemp == "0")
			cout << numb_str[0] << endl;
		else if(ntemp == "1")
			cout << numb_str[1] << endl;
		else if(ntemp == "2")
			cout << numb_str[2] << endl;
		else if(ntemp == "3")
			cout << numb_str[3] << endl;
		else if(ntemp == "4")
			cout << numb_str[4] << endl;
		else if(ntemp == "5")
			cout << numb_str[5] << endl;
		else if(ntemp == "6")
			cout << numb_str[6] << endl;
		else if(ntemp == "7")
			cout << numb_str[7] << endl;
		else if(ntemp == "8")
			cout << numb_str[8] << endl;
		else if(ntemp == "9")
			cout << numb_str[9] << endl;
		else if(ntemp == "zero")
			cout << str_numb[0] << endl;
		else if(ntemp == "one")
			cout << str_numb[1] << endl;
		else if(ntemp == "two")
			cout << str_numb[2] << endl;
		else if(ntemp == "three")
			cout << str_numb[3] << endl;
		else if(ntemp == "four")
			cout << str_numb[4] << endl;
		else if(ntemp == "five")
			cout << str_numb[5] << endl;
		else if(ntemp == "six")
			cout << str_numb[6] << endl;
		else if(ntemp == "seven")
			cout << str_numb[7] << endl;
		else if(ntemp == "eight")
			cout << str_numb[8] << endl;
		else if(ntemp == "nine")
			cout << str_numb[9] << endl;
		else
			cout << "Bad input! Try again!\n" << endl;
	}
}