//Vectors
#include <iostream>
#include <vector>

using namespace std;

//compute mean and median temperatues
int main() {
	// vector<double> temps;
	// double temp;
	// cout << "-------------------------------------------------------\n";
	// cout << "Please enter temperatues (double): \n";
	// while(cin>>temp){
	// 	temps.push_back(temp);
	// }
	// //compute mean temperature:
	// double sum = 0;
	// for(int i = 0; i<temps.size(); ++i){
	// 	sum += temps[i];
	// }
	// cout << "Average temperature is: " << sum/temps.size() << '\n';
	// //compute median temperature:
	// cout << "-------------------------------------------------------\n";
	// sort(temps.begin(), temps.end()); //sort temps from the beginning to the end
	// cout << "temps sorted" << endl;
	// for(int i=0; i<temps.size(); ++i){
	// 	cout << "temps[" << i << "] == " << temps[i] << endl;
	// }
	// cout << "Median temperature is: " << temps[temps.size()/2] << endl;
	
	//simple dictionary: list of sorted words
	cout << "-------------------------------------------------------\n";
	cout << "simple dictionary: list of sorted words\n";
	vector<string> words;
	string wtemp;
	while(cin>>wtemp){			//read whitespace-separated words
		words.push_back(wtemp);	//put into vector
	}
	cout << "Number of words: " << words.size() << endl;
	cout << "-------------------------------------------------------\n";
	cout << "list of words sorted: \n\n";
	sort(words.begin(), words.end());
	for(int i=0; i<words.size(); ++i){
		if(i==0 || words[i-1]!=words[i]){ //is this a new word?
			cout << words[i] << endl;
		}
	}
}