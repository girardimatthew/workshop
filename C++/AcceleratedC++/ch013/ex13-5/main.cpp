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

using std::streamsize;
using std::domain_error;

#include "../lib/Student_info.h"

string get_space(string::size_type s) {
    string::size_type n = 2;
    if (s == 2) n = 1;
    return string(n, ' ');
}

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
    sort(students.begin(), students.end(), Student_info::compare);
    
    // write the name and grades
    cout << endl;
    cout << "--- Students Report ---" << endl;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        bool isValid = students[i].valid();
        if (isValid) {
            cout << students[i].name()
                 << string(maxlen + 1 - students[i].name().size(), ' ');
            
            double final_grade = students[i].grade();
            string letter = students[i].letter();
            bool isValid = students[i].valid();
            bool fulfill_requirements = students[i].fulfill_requirements();

            std::streamsize prec = cout.precision();

            string space = get_space(letter.size());

            cout << setprecision(3) 
                 << letter
                 << space
                 << "   v: "
                 << isValid
                 << "   ff: "
                 << fulfill_requirements
                 << "   FG: "
                 << final_grade                 
                 << setprecision(prec)
                 << endl;
        }
    }
    
    cout << endl;
    cout << "--- Invalid students ---" << endl;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        if (!students[i].valid()) {
            cout << students[i].name() << endl;
        }
    }

    return 0;
}