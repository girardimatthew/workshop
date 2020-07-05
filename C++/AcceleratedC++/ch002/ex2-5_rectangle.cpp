#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    cout << "Please enter the length of the horizontal side of your rectangle: ";
    int column;
    cin >> column;
    cout << "Please enter the length of the vertical side of your rectangle: ";
    int row;
    cin >> row;

    cout << endl;
    for (int i = 0; i < row; ++i) {
        cout << " ";
        for (int j = 0; j < column; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}