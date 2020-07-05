// *********************************************************************************
// struct Example
// ---------------------------------------------------------------------------------
// Write a program that lets the user fill in a single structure 
// with the name, address, and phone number of a single person
// ---------------------------------------------------------------------------------
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <string>

using namespace std;

struct Person {
	string name;
	string address;
	string phone_number;
};

int main() {
	Person newPerson;

	cout << "Please enter your name: ";
	getline(cin,newPerson.name);
	cout << "Please enter your address: ";
	getline(cin,newPerson.address);
	cout << "Please enter your phone number: ";
	getline(cin,newPerson.phone_number);

	cout << "Name: " << newPerson.name << endl;
	cout << "Address: " << newPerson.address << endl;
	cout << "Phone number: " << newPerson.phone_number << endl;
}

