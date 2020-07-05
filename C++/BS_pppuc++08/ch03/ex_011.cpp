#include <iostream>

using namespace std;

int main() {
	int pen, nick, dim, quart, hdol, dol;

	cout << "How many pennies do you have?" << endl;
	cin >> pen;
	cout << "How many nickles do you have?" << endl;
	cin >> nick;
	cout << "How many dimes do you have?" << endl;
	cin >> dim;
	cout << "How many quarters do you have?" << endl;
	cin >> quart;
	cout << "How many half dollars do you have?" << endl;
	cin >> hdol;
	cout << "How many dollars do you have?" << endl;
	cin >> dol;

	cout << "------------------------------------------------" << endl;
	if (pen > 1 || pen == 0){
		cout << "You have " << pen << " pennies" << endl;
	}
	else{
		cout << "You have " << pen << " penny" << endl;
	}
	if (nick > 1 || nick == 0){
		cout << "You have " << nick << " nickles" << endl;
	}
	else{
		cout << "You have " << nick << " nickle" << endl;
	}
	if (dim > 1 || dim == 0){
		cout << "You have " << dim << " dimes" << endl;
	}
	else{
		cout << "You have " << dim << " dime" << endl;
	}
	if (quart > 1 || quart == 0){
		cout << "You have " << quart << " quarters" << endl;
	}
	else{
		cout << "You have " << quart << " quarter" << endl;
	}
	if (hdol > 1 || hdol == 0){
		cout << "You have " << hdol << " half dollars" << endl;
	}
	else{
		cout << "You have " << hdol << " half dollar" << endl;
	}
	if (dol > 1 || dol == 0){
		cout << "You have " << dol << " dollars" << endl;
	}
	else{
		cout << "You have " << dol << " dollar" << endl;
	}
	cout << "The value of all your coins is " << pen*1 + nick*5 + dim*10 + quart*25 + hdol*50 + dol*100 << " cents." << endl;
	cout << "The sum in dollars is $" << (pen*1 + nick*5 + dim*10 + quart*25 + hdol*50 + dol*100)*0.01 << endl;
}