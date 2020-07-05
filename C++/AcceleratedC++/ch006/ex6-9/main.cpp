#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

#include "grade.h"
#include "Student_info.h"
#include "extract.h"

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

void print_svector(const vector<string> vs) {
    for (vector<string>::const_iterator iter = vs.begin(); iter != vs.end(); ++iter) {
        cout << *iter;
        if ((iter + 1) < vs.end())
            cout << ", ";
    }
    cout << endl;
}

int main() {
    
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
    
    // Print out students' names;
    vector<string> students_names = extract_name(students);
    print_svector(students_names);

    // without algorithm
    std::string concatenated_string;
    for (const auto &name : students_names) concatenated_string += name;
    cout << concatenated_string << endl;

    concatenated_string = "";
    // with accumulate
    concatenated_string = std::accumulate(students_names.begin(), students_names.end(), std::string(""));
    cout << concatenated_string << endl;
}
