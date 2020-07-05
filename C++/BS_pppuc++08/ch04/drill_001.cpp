//Drill 001
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i=0;
	int temp;
	while(cin>>temp){
		if(temp == '|'){
			break;
		}
		if(i==2){
			cout << endl;
			i = 0;
		}
		cout << temp << " "; 
		++i;
	}
	cout << endl;
}