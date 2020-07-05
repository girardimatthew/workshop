#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

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
    std::vector<Student_info> students, did, didnt;
    // read the student records and partition them
    Student_info student;

    std::ifstream infile;
    infile.open("students10.txt");
    read(infile, students);

    for (vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
        if (did_all_hw(*it))
            did.push_back(*it);
        else 
            didnt.push_back(*it);
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
    // do the analyses
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);
    
    return 0;
}
