//Functions
//Try this p.115
//Implement square() without using the multiplication 
//operator.
#include <iostream>

using namespace std;

//return the square of x
int square(int x){
	int s = 0;
	for(int j = 0; j < x; ++j){
		s += x;
	}
	return s;
}

int main() {
	cout << "------------------------------------------------" << '\n';
	cout << "examples of how to use a function" << '\n';
	cout << "------------------------------------------------" << '\n';
	for(int i = 0; i<=10; ++i){
		cout<< "square(" << i << ") == " << square(i) << '\n';
	}
}