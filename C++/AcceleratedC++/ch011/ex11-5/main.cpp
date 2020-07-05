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

#include <chrono>
using std::chrono::steady_clock;

string get_space(string::size_type s) {
    string::size_type n = 2;
    if (s == 2) n = 1;
    return string(n, ' ');
}

void instrumenting_the_Student_into_class() {
    Student_info::reset_class_info();

    Student_info record { "Ciccio Salciccio", 0, 0, 0, false };
    // ===============================================================
    Student_info record2 = record;
    Student_info record3;
    Student_info record4 = record3;
    Student_info record5;
    Student_info::print_class_info(cout);
    
}

int main() {

    Student_info::reset_class_info();

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // ===============================================================
    steady_clock::time_point begin = std::chrono::steady_clock::now();
    // read and store the data
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Microseconds to read: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
    Student_info::print_class_info(cout);
    // ===============================================================

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    // write the name and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        
        double final_grade = students[i].grade();
        string grade = students[i].pass_or_fail();
        string letter = students[i].letter();
        streamsize prec = cout.precision();

        string::size_type letterSize = letter.size();
        string space = get_space(letterSize);
        
        cout << setprecision(3) 
             << letter 
             << space
             << ": "
             << grade
             << " - "
             << final_grade
             << setprecision(prec) 
             << endl;
    }
    Student_info::print_class_info(cout);

    // 
    instrumenting_the_Student_into_class();
    Student_info::print_class_info(cout);
    return 0;
}