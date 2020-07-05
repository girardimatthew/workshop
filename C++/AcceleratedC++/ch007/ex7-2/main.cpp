/*
    Assign letter grades by ranges:
    A 90-100
    B 80-89.99
    C 70-79.99
    D 60-60.99
    F < 60
    The output should list how many students fall into each category.
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include "grade.h"
#include "Student_info.h"

using std::cin;                 using std::setprecision;        using std::map;
using std::cout;                using std::sort;                using std::logic_error;
using std::domain_error;        using std::streamsize;
using std::endl;                using std::string;
using std::max;                 using std::vector;

void print_new_line() {
    cout << endl;
}

void print_grades_rule() {
    cout << "=== Letter grades by ranges ===" << endl;
    cout << "A: 90 - 100" << endl;
    cout << "B: 80 - 89.99" << endl;
    cout << "C: 70 - 79.99" << endl;
    cout << "D: 60 - 69.99" << endl;
    cout << "F: < 60" << endl;
    print_new_line();
}

string map_grade(double g) {
    if (g >= 90.0 && g <= 100) {
        return "A";
    } else if (g >= 80 && g < 90.0) {
        return "B";
    } else if (g >= 70 && g < 80.0) {
        return "C";
    } else if (g >= 60 && g <= 70.0) {
        return "D";
    } else if (g < 60) {
        return "F";
    } else {
        throw logic_error("grade out of mapping range");
        //return "!?"; // Wrong grade!
    }
}

int main() {
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;   // the length of the longest name
    vector<double> grades;
    map<string, int> students_number_by_grades;

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

    // write grades rule
    print_grades_rule();

    // write the names and grades
    cout << "=== Students grades ===" << endl;
    for (vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << it->name
             << string(maxlen + 1 - it->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*it);
            grades.push_back(final_grade);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        print_new_line();
    }
    print_new_line();

    // map each grade into a letter grade and store it into a map
    for (vector<double>::const_iterator it = grades.begin(); it != grades.end(); ++it) {
        try {
            string letter_grade = map_grade(*it);
            ++students_number_by_grades[letter_grade];
        } catch (logic_error e) {
            cout << e.what() << endl;
            exit(1);
        }
    }

    // write list how many students fall into each category
    cout << "=== Number of Students by category ===" << endl;
    for (map<string, int>::const_iterator it = students_number_by_grades.begin(); it != students_number_by_grades.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}