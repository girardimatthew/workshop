// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 15
// P. 127
// *********************************************************************************
// Write a program that takes an input value n and then finds the first n primes
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	vector<double> prime;

	int num_of_primes=0;
	int r, m, n=2;
	int first;

	cout << "How many prime numbers to you want to find?\n";
	cin >> num_of_primes;
	if (num_of_primes<1) {
		cout << "then what the **** do you want boy??\n";
		exit(1);
	}
	else if (num_of_primes==1) {
		cout << "Searching for the first prime......\n";
	}
	else {
		cout << "Searching for the first " << num_of_primes << " primes.....\n";
	}
 
 	while (prime.size()<=num_of_primes-1) {
 		first=0;
 		for (int j=2; j<n; ++j) {
 			if (n%j!=0) {
 				++first;
 			}
 		}
 		if (first==(n-2)){
 			prime.push_back(n);
 		}
 		++n;
 	}

 	if (num_of_primes==1) {
 		cout << "The first prime is:\n";
 	}
 	else {
 		cout << "The first " << num_of_primes << " primes found are: \n";	
 	}
	for (int i=0; i<prime.size(); ++i){
		cout << prime[i] << " ";
	}

	cout << endl;
}