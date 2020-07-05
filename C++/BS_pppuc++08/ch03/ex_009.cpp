#include <iostream>

using namespace std;

int main() {
	string s0 = "zero";
	string s1 = "one";
	string s2 = "two";
	string s3 = "three";
	string s4 = "four";

	string ins = "";

	cout << "Plese, enter a number between 0 and 4" << endl;
	cout << "Remeber to write such number in letters" << endl;
	cin >> ins;

	if (ins == s0){
		cout << "0" << endl;
	}
	else if (ins == s1){
		cout << "1" << endl;
	}
	else if (ins == s2){
		cout << "2" << endl;
	}
	else if (ins == s3){
		cout << "3" << endl;
	}
	else if (ins == s4){
		cout << "4" << endl;
	}
	else{
		cout << "not a number I know" << endl;
	}
}
