#include "../std_lib_facilities_v2.h"
#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
    try {
        double value = 0;
        while (true) {
            cout << "Please enter an integer value: \n";
            cout << "> ";
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Please enter an integer value: \n";
                cout << "> ";

            }
            else 
                cout << "value: " << value << endl;
        }
    }
    catch (exception& e) {
    	cerr << "ERROR CODE: " << e.what() << endl;
        keep_window_open("~1");
        return 1;

    }
    catch (...) {
    	cerr << "An unknown error has occurred." << endl;
        keep_window_open("~2");
        return 2;
    }
    return 0;
}