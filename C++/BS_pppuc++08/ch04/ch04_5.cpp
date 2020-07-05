//Functions
#include <iostream>

using namespace std;

//return the square of x
int square(int x){
	return x*x;
}

void write_sorry(){
	cout << "Sorry!\n";
}

void print_square(int v) {
	cout << v << '\t' << v*v << '\n';
}

int main() {
	cout << "------------------------------------------------" << '\n';
	cout << "examples of how to use a function" << '\n';
	cout << "------------------------------------------------" << '\n';
	cout << "square(2) == " << square(2) << '\n';
	cout << "square(100) == " << square(100) << '\n';

	cout << "------------------------------------------------" << '\n';
	cout << "examples of how to use a void function" << '\n';
	cout << "------------------------------------------------" << '\n';
	write_sorry();

	for(int i = 0; i <= 100; ++i){
		print_square(i);
	}

}