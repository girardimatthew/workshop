// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ch 03
// P. 59

#include <iostream>
#include <vector>

using namespace std;

int main() {
	//3.1 Input
	cout << "Please enter your first name and age: \n";
	string first_name = "????";
	string second_name = "????";
	int age = -1;
	int months = -1;
	cin >> first_name >> second_name >> age >> months;
	cout << " ------------------------------------------------------ \n";
	cout << "Hello, " << first_name << " " << second_name << "!\n";
	cout << "(age: " << age << " years old - " << (age*12) + months << " months old)\n";
}