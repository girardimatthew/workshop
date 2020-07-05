// Ansi Table

#include <cstdlib>
#include <iostream>
//#include "../std_lib_facilities_v2.h"
#include <vector>
#include <exception>
#include <string>

using namespace std;

int main() {

	for (int i=0; i<128; ++i) {
		cout << i << ": " << (char)i << endl;
	}
}