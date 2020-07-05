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

#include "Core.h"
#include "Grad.h"

int main() {
    vector<Core*> students;             // store pointers, not objects
    Core* record;                       // temporary must be a pointer as well
    char ch;
    string::size_type maxlen = 0;

    // read and store the data
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;          // allocate a Core object
        else 
            record = new Grad;          // allocate a Grad object
        record->read(cin);              // virtual call
        maxlen = max(maxlen, record->name().size());    // dereference
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare_Core_ptrs);
    // write the name and grades
    for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
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
        delete students[i];             // free object allocated when reading.
    }
    return 0;
}