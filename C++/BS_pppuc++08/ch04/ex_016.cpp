// *********************************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 16
// P. 128
// *********************************************************************************
// Write a program that finds the mode of a set of positive integers
// *********************************************************************************
// However, I did something slightly different from what asked in ex. 16
// Finding the mode (or modes), mean, median, largest and smallest 

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int count=0, ceil=0, whereat=-1;
	double din=0, smallest=0, largest=0, sum=0, median=0, prev;
	vector<double> nseq;
	vector<double> mode;
	vector<int> indexof;
	vector<int> howmany;
	vector<double> whatnum;

	cout << "Finding the smallest, the largest and the mode of as series of integer numbers.\n";
	cout << "Please enter a sequence of digits (to exit e): \n";
	
	// storing the input numbers into a vector
	while (cin>>din) {
		if (din=='e') {
			break;
		}
		else {
			nseq.push_back(din);	
		}
	}

	// sorting the input sequence
	sort(nseq.begin(), nseq.end());
	smallest=nseq[0];
	largest=nseq[nseq.size()-1];

	if (nseq.size()==1) {
		cout << "The input is just one value, not a sequence." << endl;
		exit(0);
	}

	// counting the occurence of each number
	for (int i=0; i<nseq.size(); ++i) {
		sum+=nseq[i];
		if (i==0) {
			prev=nseq[i];
		}
		else if (i>0 && i<nseq.size()-1) {
			if (nseq[i]==prev){
				++count;
				prev=nseq[i];
			}
			else {
				whatnum.push_back(nseq[i-1]);
				indexof.push_back(i-1);
				howmany.push_back(count+1);
				prev=nseq[i];
				count=0;
			}
		}
		else {
			if (nseq[nseq.size()-1]==prev) {
				++count;
				whatnum.push_back(nseq[i]);
				indexof.push_back(i);
				howmany.push_back(count+1);
			}
			else {
				whatnum.push_back(nseq[i-1]);
				indexof.push_back(i-1);
				howmany.push_back(count+1);
				count=0;
				whatnum.push_back(nseq[i]);
				indexof.push_back(i);
				howmany.push_back(count+1);
			}
		}
	}

	// finding the mode
	count=1;
	for (int i=0; i<howmany.size(); ++i) {
		if (howmany[i]>count) {
			count=howmany[i];
			whereat=indexof[i];
		}
	}
	if (whereat!=-1) {
		mode.push_back(nseq[whereat]);
	}
	// finding if there is more than one mode
	for (int i=0; i<howmany.size(); ++i) {
		if (howmany[i]==count && indexof[i]!=whereat && howmany[i]>1) {
			whereat=indexof[i];
			mode.push_back(nseq[whereat]);
		}
	}

	// finding the median value of the input sequence
	if (nseq.size()%2!=0) {
		median=nseq[nseq.size()/2];
	}
	else {
		median=(nseq[(nseq.size()/2)-1] + nseq[nseq.size()/2]) / 2.0;
	}

	// print the input sequence sorted
	cout << "-----------------------------------------------------\n";
	for (int i=0; i<nseq.size(); ++i) {
		cout << nseq[i] << ", ";
	}
	cout << endl;
	// check if the loop works
	// cout << "-----------------------------------------------------\n";
	// for (int i=0; i<indexof.size(); ++i) {
	// 	cout << "indexof[" << i << "]: " << indexof[i] << ", howmany[" << i << "]: " << howmany[i] << ", >> " << nseq[indexof[i]] << endl;
	// }
	cout << "-----------------------------------------------------\n";
	if (mode.size()>1) {
		cout << "The smallest values is: " << smallest << endl;
		cout << "The largest values is: " << largest << endl;
		cout << "The mean is equal to " << sum/nseq.size() << endl;
		cout << "The modes are: ";
		for (int i=0; i<mode.size(); ++i) {
			cout << mode[i] << ", ";
		}
		cout << endl;
		cout << "The median value is: " << median << endl;
	}
	else if (mode.size()==0) {
		cout << "The smallest values is: " << smallest << endl;
		cout << "The largest values is: " << largest << endl;
		cout << "The mean is equal to " << sum/nseq.size() << endl;
		cout << "No mode found." << endl;
		cout << "The median value is: " << median << endl;
	}
	else {
		cout << "The smallest values is: " << smallest << endl;
		cout << "The largest values is: " << largest << endl;
		cout << "The mean is equal to " << sum/nseq.size() << endl;
		cout << "The mode is: " << mode[0] << endl;
		cout << "The median value is: " << median << endl;
	}
}