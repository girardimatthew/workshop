//
//  main.cpp
//  ex5-0
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "extract_fails.h"
#include "grade.h"
#include "Student_info.h"

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

int main(int argc, const char * argv[]) {
    
    vector<Student_info> students;
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
    
    // extract failing students
    vector<Student_info> fStudents= extract_fails(students);
    
    // write the names and grades
    for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
        
        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    
    cout << "\n=== Failing Students === \n";
    
    for (vector<Student_info>::const_iterator iter = fStudents.begin(); iter != fStudents.end(); ++iter) {
        cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
    
        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    
    return 0;
}

