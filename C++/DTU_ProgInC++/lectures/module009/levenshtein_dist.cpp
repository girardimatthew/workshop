// *********************************************************************************
// Programming in C++ 
// Exercise 003 - mod09
// levenshtein distance (LD)
// Matteo Girardi
// *********************************************************************************

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int min3(int a, int b, int c) {
	int m = min(a,b);
	return min(m,c);
	// bad...
	// if ((a<=b) && (a<=c)) return a;
	// if ((b<=a) && (b<=c)) return b;
	// if ((c<=a) && (c<=b)) return c;
}

int leven_Dist(string w1, int len_w1, string w2, int len_w2) {
	int f;
	if (len_w1==0) return len_w2;
	if (len_w2==0) return len_w1;

	if(w1[0]==w2[0]) f = 0;
	else f = 1;

	return min3(leven_Dist(w1.substr(1), len_w1-1, w2, len_w2) + 1, 
				leven_Dist(w1, len_w1, w2.substr(1), len_w2-1) + 1,
				leven_Dist(w1.substr(1), len_w1-1, w2.substr(1), len_w2-1) + f);

}

int main() {
	string w1, w2;
	cin >> w1 >> w2;
	int len_w1 = w1.size();
	int len_w2 = w2.size();

	cout << leven_Dist(w1,len_w1,w2,len_w2) << endl;
}

// ---------------------------------
// TESTS
// input					output
// ---------------------------------
// red pen					2
// superman batman			5
// copenhagen koebenhavn 	5