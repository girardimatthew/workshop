#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

void print_name(const vector<Student_info> v) {
    for (vector<Student_info>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        cout << iter->name;
        if ((iter + 1) < v.end())
            cout << ", ";
    }
    cout << endl;
}

int main() {
    
    vector<Student_info> students;
    vector<Student_info> copy_students;
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
    sort(students.begin(), students.end(), compare);
    // 
    copy_students = students;
    
    // extract record for failing student
    vector<Student_info> failing_s = extract_fails(students);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name 
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
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
    for (vector<Student_info>::size_type i = 0; i != failing_s.size(); ++i) {
        cout << failing_s[i].name;
        if ((i + 1) < failing_s.size())
            cout << ", ";
    }
    cout << endl;

    cout << endl << "Students that did not do all the homework: " << endl;    
    vector<Student_info> didnt_do_all_homework = extract_didnt_all_hw(copy_students);
    print_name(didnt_do_all_homework);
    cout << endl;
    return 0;
}
