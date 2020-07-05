#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i <= 10; ++i){
		if ((i%2) == 1) {
			cout << "The value " << i << " is an odd number." << endl;
		}
		else 
			cout << "The value " << i << " is an even number." << endl;
	}
}
