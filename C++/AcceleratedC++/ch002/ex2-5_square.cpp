#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    // ask for the size of the square
    cout << "Please enter the lenght of a square's side: ";
    // read the name
    int side;
    cin >> side;

    cout << endl;
    for (int i = 0; i < side; ++i) {
        cout << " ";
        for (int j = 0; j < side; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}