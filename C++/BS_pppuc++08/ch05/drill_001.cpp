// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// CH 05 Drill
// *********************************************************************************
// Drill 001
// *********************************************************************************

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../std_lib_facilities_v2.h"

using namespace std;

int main() {
	int drill = 0;
	try {
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		cout << "Success!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		cout << "Success!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		cout << "Success" << "!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		cout << "Success!" << endl;
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		int res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "v[5]==" << v[5] << " - Success!\n";
		
		// range error
		//cout << "Drill " << ++drill << ": v[22]==" << v[22] << endl;

		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if (v[5]==7)
			cout << "Success!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if(v[5]!=7) 
			cout << "Fail!\n";
		else 
			cout << "Success!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		bool c = false;
		if (c)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		string s = "ape";
		string w = "fool";
		if (s<w)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if (s==w)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if (s==w)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if (s==w)
			cout << "Success!\n";
		else 
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		vector<char> x(5);
		for (int i=0; i<x.size(); ++i) {
			cout << "Success!" << "[" << i << "]\n";
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		for (int i=0; i<=x.size(); ++i) {
			cout << "Drill " << drill << ": Success!" << "[" << i << "]\n";
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		string ss = "Success!\n";
		for (int i=0; i<ss.length()-1; ++i) {
			cout << "ss[" << i << "]: " << ss[i] << "\n";	
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		if (true)
			cout << "Success!\n";
		else 
			cout << "Fail!\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		int n = 2000;
		char p = n;
		if (p==n)
			cout << "Success! (" << p << ", " << n << ")\n";
		else 
			cout << "Fail! (" << p << ", " << n << ")\n";
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		for (int i=0; i<10; ++i) {
			cout << "ss[" << i << "]: " << ss[i] << "\n";	
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		vector<int> ii =  {1,2,3,4,5};
		// range error
		// for (int i=0; i<=ii.size(); ++i) {
		// 	cout << "Drill " << drill << ": " << ii[i] << "\n";		
		// }
		for (int i=0; i<ii.size(); ++i) {
			cout << "Drill " << drill << ": " << ii[i] << "\n";		
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		int xx = 0;
		int jj = 9;
		while (xx<15) {
			if (xx<jj) {
				cout << "xx==" << xx << " - Success!\n";
			}
			else {
				cout << "xx==" << xx << " - Fail!\n";
			}
			++xx;
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		int xxx = 2;
		double ddd = 5/(xxx-1);
		if (ddd==2*xxx+0.5) {
			cout << "ddd==" << ddd << " - Success!\n";
		}
		else {
			cout << "ddd==" << ddd << " - Fail!\n";
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		vector<char> sscc = {'S','u','c','c','e','s','s','!'};
		for (int i=0; i<sscc.size(); ++i) {
			cout << "sscc[" << i << "]: " << sscc[i] << "\n";	
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		int kkk=10;
		int iii=5;
		while (kkk>0) {
			if (kkk>iii) {
				cout << "kkk==" << kkk << " - Success!\n";
			}
			else {
				cout << "kkk==" << kkk << " - Fail!\n";
			}
			--kkk;
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		double mmm=4.0;
		double nnn=5.0/(mmm-2.0);
		if (nnn!=2.0*mmm+0.5) {
			cout << nnn << "!=" << 2.0*mmm+0.5 << " - Fail!\n";
		}
		else {
			cout << nnn << "==" << 2.0*mmm+0.5 << " - Success!\n";	
		}
		cout << "------------------- DRILL " << ++drill << " ----------------------\n";
		cout << "Success!\n";
		
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}

