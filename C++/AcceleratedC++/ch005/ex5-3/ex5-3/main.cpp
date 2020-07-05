#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"
#include "StudentInfoContainerType.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::list;

int main() {
    
    StudentInfoContainerType students;
    Student_info record;
    string::size_type maxlen = 0;   // the length of the longest name

    // read and store all the student's data.
    // Invariant:   students contains all the student records read so far
    //              maxlen contains the length for the longest name in students
    while (read(cin, record)) {
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    // when using list
    students.sort(compare);
    
    // when using vector
    // sort(students.begin(), students.end(), compare);
    
    // extract record for failing student
    StudentInfoContainerType failing_s = extract_fails(students);

    // write the names and grades
    cout << endl;
    cout << endl << "Passing students: " << endl;
    for (StudentInfoContainerType::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name
             << string(maxlen + 1 - iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
            
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    
    
    cout << endl << "Failing students: " << endl;
    // write the failing students
    for (StudentInfoContainerType::const_iterator iter = failing_s.begin(); iter != failing_s.end(); ++iter) {
        
        cout << "    > " << iter->name << endl;
    }
    cout << endl;
    return 0;
}
