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


int main() {
    
    // students who did and didn't do all their homework
    std::vector<Student_info> did, didnt;
    // read the student records and partition them
    Student_info student;

    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else 
            didnt.push_back(student);
    }

    // verify that the analyses will show us something
    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }
    // dod the analyses
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
    
    return 0;
}


// int main() {
    
//     std::vector<Student_info> students;
//     std::vector<Student_info> did, didnt;
//     Student_info record;
//     string::size_type maxlen = 0;   // the length of the longest name

//     // read and store all the student's data.
//     // Invariant:   students contains all the student records read so far
//     //              maxlen contains the length for the longest name in students
//     // read all the records, separating them based on whether all homework was done.
//     while (read(cin, record)) {
//         if (did_all_hw(record))
//             did.push_back(record);
//         else 
//             didnt.push_back(record);
//         // find length of longest name
//         maxlen = max(maxlen, record.name.size());
//         students.push_back(record);
//     }

//     // check that both groups contain data
//     if (did.empty()) {
//         cout << "No student did all the homework!" << endl;
//         return 1;
//     }

//     if (didnt.empty()) {
//         cout << "Every student did all the homework!" << endl;
//         return 1;
//     }

//     // alphabetize the student records
//     sort(students.begin(), students.end(), compare);
    
//     // extract record for failing student
//     vector<Student_info> failing_s = extract_fails(students);

//     // write the names and grades
//     for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        
//         // write the name, padded on the right to maxlen + 1 characters
//         cout << students[i].name 
//              << string(maxlen + 1 - students[i].name.size(), ' ');

//         // compute and write the grade
//         try {
//             double final_grade = grade(students[i]);
//             streamsize prec = cout.precision();
//             cout << setprecision(3) << final_grade
//                  << setprecision(prec);
            
//         } catch (domain_error e) {
//             cout << e.what();
//         }
//         cout << endl;
//     }
    
    
//     cout << endl << "Failing students: " << endl;
//     // write the failing students
//     for (vector<Student_info>::size_type i = 0; i != failing_s.size(); ++i) {
//         cout << failing_s[i].name;
//         if ((i + 1) < failing_s.size())
//             cout << ", ";
//     }
//     cout << endl;
//     return 0;
// }
