// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 4
// P. 126
// *********************************************************************
// Write a program to play a numbers guessing game. 
// The user thinks of a number between 1 and 100 and 
// your program asks questions to figure out what the number is 
// (e.g., "Is the number you are thinking of less than 50?"). 
// Your program should be able to identify the number after 
// asking no more than seven questions. 
// Hint: Use the < and <= operators and the if-else construct
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	string input;

	cout << "Guess a number between 1 and 100.\n";
	cout << "Is the number you are thinking of less than 50?\n";
	cin >> input;
	if(input == "no"){
		cout << "Is the number you are thinking of less than 75?\n";
	}
	else{
		cout << "Is the number you are thinking of less than 25?\n";
	}

}