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

using std::cin;                 using std::max;
using std::cout;                using std::setprecision;
using std::domain_error;        using std::sort;
using std::endl;                using std::streamsize;
using std::string;              using std::vector;

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
    write_analysis(cout, "median: ", median_analysis, did, didnt);
    write_analysis(cout, "average: ", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in: ", optimistic_median_analysis, did, didnt);
    
    return 0;
}