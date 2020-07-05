#include <iostream>
#include <math.h>

using namespace std;

//calculate and print a table of squares 0-100
int main() {
	cout << "----------------------------------------------------------" << endl;
	cout << "Use a loop (while-statement) to write a table of squares" << endl;
	cout << "----------------------------------------------------------" << endl;
	int i = 0;
	while (i<=100){
		cout << i << '\t' << i*i << '\n';
		++i;
	}

	cout << "----------------------------------------------------------" << endl;
	cout << "Use a loop (while-statement) to write a table of characters with" << endl;
	cout << "their corresponding integer values" << endl;
	cout << "----------------------------------------------------------" << endl;

	int j = 0;
	while (j<=29){
		cout << char('a'+j) << '\t' << int('a'+j) << endl;
		++j;
	}

	cout << "----------------------------------------------------------" << endl;
	cout << "Use a loop (for-statement) to write a table of squares" << endl;
	cout << "----------------------------------------------------------" << endl;

	for(int i = 0; i <= 100; ++i){
		cout << i << '\t' << i*i << '\n';
	}

	cout << "----------------------------------------------------------" << endl;
	cout << "Use a loop (for-statement) to write a table of characters with" << endl;
	cout << "their corresponding integer values" << endl;
	cout << "----------------------------------------------------------" << endl;

	for (int j = 0; j <= 93; ++j){
		cout << char('!'+j) << '\t' << int('!'+j) << endl;
	}
}