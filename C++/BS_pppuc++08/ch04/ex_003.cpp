// *********************************************************************
// Bjarne Stroustrup
// Programming: Principles and Practice Using C++
// Ex 3 
// P. 126
// *********************************************************************
// Read a sequence of double values into a vector. 
// Think of each value as the distance between two cities along a given route. 
// Compute and print the total distance (the sum of all distances). 
// Find and print the smallest and greatest distance between two neighboring cities. 
// Find and print the mean distance between two neighboring cities
// *********************************************************************

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> dists;
	double temp, sum, min, max, mean;
	sum = 0;

	while (cin>>temp)
		dists.push_back(temp);

	cout << "-----------------------------------------------------------" << endl;
	cout << "Number of dists: " << dists.size() << endl;
	for (int i = 0; i < dists.size(); ++i) {
		cout << "dists[" << i << "] == " << dists[i] << endl;
	}

	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < dists.size(); ++i) {
		sum += dists[i];
	}
	cout << "The sum of all distances is: " << sum << endl;

	cout << "------------------------- SORTED --------------------------" << endl;
	sort(dists.begin(), dists.end());		//sort "from beginning to end"
	for (int i = 0; i < dists.size(); ++i) {
		cout << "dists[" << i << "] == " << dists[i] << endl;
	}
	cout << "------------------------- MIN & MAX -----------------------" << endl;
	cout << "min distance is: " << dists[0] << endl;
	cout << "max distance is: " << dists[dists.size()-1] << endl;

	cout << "------------------------- MEAN ----------------------------" << endl;

	cout << "Mean distance is: " << sum/dists.size() << endl; 
}