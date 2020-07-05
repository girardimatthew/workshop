//Try this 
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout << "-------------------------------------------------------\n";
	cout << "simple dictionary: list of sorted words\n";
	vector<string> words;
	string temp;
	string dislike = "Broccoli";
	while(cin>>temp){			//read whitespace-separated words
		if(temp!=dislike){
			cout << temp << ' ';
		}
		else if(temp==dislike){
			cout << "BLEEP" << ' ';
		}
	}
	cout << endl;
}