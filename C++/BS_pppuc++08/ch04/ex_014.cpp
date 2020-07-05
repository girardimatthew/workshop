// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 14
// P. 127
// *********************************************************************************
// Modify the program described in the previous exercise to take an input
// value max and then find all prime numbers from 1 to max.
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int n, p=2, m=2;
	vector<int> primes;
	vector<int> pmultiples;
	vector<int> numbers;

	cout << "*** SEARCHING PRIME NUMBERS ***\n";
	cout << "Please enter a value (starting from 3) so that the program will find prime numbers from 1 to value.\n";
	cin >> n;
	if (n<3) {
		cout << "Bad input. Try to use a higher value.\n";
		exit(1);
	}
	else {
		cout << "Searching prime numbers up to " << n << " ....\n";
		cout << n << " is not included!\n";
	}

	// create a list of consecutive integers from 2 to n
	for (int i=2; i<=n; ++i) {
		numbers.push_back(i);
	}
	vector<int> index(numbers.size(),0);

	// Enumerate the multiples of p by counting to n from 2p in increments of p
	// and save the index of such list.
	while (p<n) {
		m+=p;
		for (int i=0; m<n; ++i) {
			if(numbers[i]==m) {
				index[i]=1;
				m+=p;
			}
		}
		// find the first number greater than p in the list that is not marked.
		// if there is such number, let p now equal this new number and repeat
		for (int i=0; i<n; ++i){
			if(index[i]==0 && numbers[i]>p){
				p=numbers[i];
				m=p;
				break;
			}
		}
	}

	// just checking...
	// for (int i=0; i<index.size(); ++i) {
	// 	cout << "numbers[" << i << "]: " << numbers[i] << ", index[" << i << "]: " << index[i] << endl;
	// }

	for (int i=0; i<index.size(); ++i) {
		if (index[i]==0){
			primes.push_back(numbers[i]);
		}
	}

	cout << "*** THE PRIME NUMBERS FOUND ARE ***\n";
	int count=1;
	for (int i=0; i<primes.size()-1; ++i){
		cout << primes[i] << " ";
		if (count==10){
			cout << endl;
			count=1;
		}
		++count;
	}
	cout << endl;

}