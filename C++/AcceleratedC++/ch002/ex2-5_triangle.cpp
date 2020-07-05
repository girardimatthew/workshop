#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    // ask for the size of the square
    cout << "Please enter the size of your triangle: ";
    int row;
    cin >> row;

    int column = row + (row - 1);
    int indexOfMidColumn = column / 2;

    cout << endl;
    for (int i = 0; i < row; ++i) {
        cout << " ";
        for (int j = 0; j < column; ++j) {
            if ((j >= (indexOfMidColumn - i)) && (j <= (indexOfMidColumn + i))) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}