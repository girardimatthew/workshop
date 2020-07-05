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

void core_constructor() {
    Core* pc = new Core();
    delete pc;
}

void grad_constructor() {
    Grad* pg = new Grad();
    delete pg;
}

int main() {

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    cout << "--- start reading cin ---" << endl;
    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
        cout << "\t\t ---" << endl;
    }
    cout << "--- end reading cin ---" << endl;

    // alphabetize the student records
    sort(students.begin(), students.end(), Student_info::compare);
    // write the name and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade(); // Grad::grade
            std::streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (std::domain_error e) {
            cout << e.what() << endl;
        }
    }

    //
    cout << endl;
    cout << "--- core_constructor ---" << endl;
    core_constructor();
    cout << "--- grad_constructor ---" << endl;
    grad_constructor();
    cout << "---" << endl;
    cout << endl;
    
    return 0;
}