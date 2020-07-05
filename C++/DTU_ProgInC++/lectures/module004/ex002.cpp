// *********************************************************************************
// Programming in C++ 
// Exercise 002 - mod04
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
	int value = 0;
	int maxv = value;
	vector<int> st_int;
	vector<string> st_cmd;

	while (cin>>cmd && cmd!=quit) {
		st_cmd.push_back(cmd);
		cin >> value;
		if (value>maxv) maxv = value;
		st_int.push_back(value);
	}

	vector<int> set(maxv+1);
	for (int i=0; i<set.size(); ++i) {
		set[i]=0;
	}

	for (int i=0; i<st_cmd.size(); ++i) {
		if (st_cmd[i]==add) { set[st_int[i]]+=1; }
		if (st_cmd[i]==del) { set[st_int[i]]==0 ? set[st_int[i]]=0 : set[st_int[i]]-=1; }
		if (st_cmd[i]==qry) { set[st_int[i]]>0 ? cout << "T" : cout << "F"; }
	}
	cout << endl;
}