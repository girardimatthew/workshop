#include <vector>
using std::vector;

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

#include "Student_info.h"

using std::streamsize;
using std::domain_error;

int main() {

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    // write the name and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        
        double final_grade = students[i].grade();
        string grade = students[i].pass_or_fail();
        streamsize prec = cout.precision();
        
        cout << setprecision(3) 
             << grade
             << " - "
             << final_grade
             << setprecision(prec) 
             << endl;
    }

    return 0;
}