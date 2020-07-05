// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ed: 2008
// CH 05 Exercises
// Ex 012
// *********************************************************************************
// Implement a little guessing game called (for some obscure reason) 
// "Bulls and Cows". The program has a vector of four integers in the range 0 to 9
// and it is the user's task to discover those numbers by repeated guesses.
// Say the number to be guessed is 1234 and the user guesses 1359; the response 
// should be "1 bull and 1 cow" because the user got one digit (1) right and in the 
// right position (a bull) and one digit (3) right but in the wrong position (a cow).
// The guessing continues unti the user gets four bulls, that is, has the four digits
// correct and in the correct order.
// *********************************************************************************


#include <cstdlib>
#include <iostream>
//#include "../std_lib_facilities_v2.h"
#include <vector>
#include <exception>
#include <string>

using namespace std;

int main() {
	try {
		string n = "1234";
		string input = "0";
		vector<char> answer;
		vector<char> guess;
		bool state = true;
		bool checkinput = true;
		int bull = 0;
		int cow = 0;

		for(int i=0; i<n.size(); ++i) {
			answer.push_back(n[i]);
		}

  		cout << "----------------- BULLS AND COWS ------------------- \n";
  		cout << "The player guesses a 4-digit number.\n";
  		cout << "Bull means that you correctly guessed one or more digits \nand they are in the right place.\n";
  		cout << "Cow means that you guessed one or more digit however thay are not in the right place.\n";
  		cout << "For instance: if the answer is '1234' and your guess is: '1359'.\n";
  		cout << "You get: 1 bull and 1 cow.\n";
  		cout << "To exit please enter '|'.\n";

  		while (state) {
  			cout << "---------------------------------------------------- \n";
  			cout << "Please enter a 4-digit number: ";
  			checkinput=true;
  			cin>>input;

  			if (input.size()==4) {
	  			for(int i=0; i<input.size(); ++i) {
	  				if ((char)input[i]>=48 && (char)input[i]<=57) {
	  					guess.push_back(input[i]);
	  				}
	  				else {
	  					cerr << "Bad input! " << input[i] << " is not a number!\n";
	  					cerr << "Please try again.\n";
	  					guess.clear();
	  					checkinput=false;
	  					break;
	  				}
				}
			}
			else if (input.size()==1 && (char)input[0]==124){
				cout << "Hope you had fun! Bye.\n";
				checkinput=false;
				exit(1);
			}
			else {
				cerr << "Bad input! Not a 4-digit number.\n";
  				checkinput=false;
			}

			if (checkinput) {
	  			for (int i=0; i<guess.size(); ++i) {
	  				for (int j=0; j<answer.size(); ++j) {
	  					if (guess[i]==answer[j] && i==j) {
	  						++bull;
	  					}
	  					else if (guess[i]==answer[j] && i!=j) {
	  						++cow;
	  					}
	  				}
	  			}
	  			if (bull==answer.size()) {
					cout << bull << " bulls, You won!\n";
	  				state = false;
	  			}
	  			else if ((bull>0 && bull<4) || (cow>0 && cow<=4)) {
	  				cout << bull << " bull and " << cow << " cow. Try again!\n";
	  				guess.clear();
	  			}
	  			else {
	  				cout << "No bull and No cow. Try again!\n";
	  				guess.clear();
	  			}
				bull=0;
	  			cow=0;
	  		}
  		}
	}
	catch (runtime_error& e) {
		cerr << "runtime error.\n";
	}
	catch (...) {
		cerr << "Unknown exception!\n";
	}
}