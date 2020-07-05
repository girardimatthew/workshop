#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <algorithm> 
using std::max;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include "Student_info.h"

int main() {
    
    using HandleCore = Handle<Core>;
    
    vector<HandleCore> students;
    HandleCore record;
    char ch;
    string::size_type maxlen = 0;

    // read and store the data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;      // allocate a Core object
        else
            record = new Grad;      // allocate a Grad object
        
        record->read(cin);          // Handle<T>::->, then virtual call to read
        maxlen = max(maxlen, record->name().size());    // Handle>T>::->
        students.push_back(record);
    }

    // compare must be rewritten to work on const Handle<Core>&
    sort(students.begin(), students.end(), compare_Core_Handles);

    // write the name and grades
    for (vector<HandleCore>::size_type i = 0; i != students.size(); ++i) {
        // students[i] is a Handle, which we dereference to call the functions
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade(); // Grad::grade
            std::streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (std::domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}