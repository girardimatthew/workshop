// *********************************************************************************
// Programming in C++ 
// Exercise 003 - mod04
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <vector>
using namespace std;

const string add="add";
const string del="del";
const string qry="qry";
const string quit="quit";

int main() {
	string cmd;
	double value = 0;
	bool found = false;
	vector<double> st_val;
	vector<int> s_counter;	

	while (cin>>cmd && cmd!=quit) {
		cin >> value;
		if (add==cmd && st_val.size()!=0) {
			found = false;
			for (int i=0; i<st_val.size(); ++i) {
				if (st_val[i]==value) { 
					++s_counter[i];
					found=true;
				}
			}
			if (found==false) {
				st_val.push_back(value);
				s_counter.push_back(1);
			}
		}
		else if (add==cmd && st_val.size()==0) { 
			st_val.push_back(value);
			s_counter.push_back(1);
		}
		else if (cmd==qry && st_val.size()==0) { cout << "F";}
		else if (cmd==qry && st_val.size()!=0) {
			for (int i=0; i<st_val.size(); ++i) {
				if (st_val[i]==value) {
					s_counter[i]>0 ? cout << "T" : cout << "F";
				}
			}
		}
		else if (cmd==del) {
			for (int i=0; i<st_val.size(); ++i) {
				if (st_val[i]==value) {
					s_counter[i]>0 ? --s_counter[i] : s_counter[i]=0;
				}
			}
		}
	}

	// just checking if everything is fine...
	// cout << endl;
	// for (int i=0; i<st_val.size(); ++i) {
	// 	cout << st_val[i] << ", " << s_counter[i] << endl;
	// }
	cout << endl;
	return 0;
}