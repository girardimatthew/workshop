#include <iostream>

using namespace std;

class alpha{
private:
	int n;
	int c;

public:
	alpha(int d, int m) {
		n = d;
		c = m;

	}

	void display(){
		cout << n << endl;
		cout << c << endl;
	}
};

int main(){

	int v1, v2;
	cin >> v1 >> v2;
	alpha dd(v1,v2);
	dd.display();

	
	return 0;
}