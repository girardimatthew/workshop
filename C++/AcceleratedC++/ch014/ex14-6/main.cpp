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

#include <sstream>
using std::stringstream;

#include "Student_info.h"
#include "Str.h"

int main() {

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), Student_info::compare);

    // write the name and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            std::streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        } catch (std::domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}