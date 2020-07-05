//ex4-6
// Rewrite the Student_info structure, and the read and grade functions,
// so that they calculate each student's grades as part of reading the input, 
// and store only the final grade

#include <string>
#include <iostream>
#include <vector>
#include "median.h"

using namespace std;

struct Student_info {
    string name;
    double finalGrade;
};

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

// compute a student's overall grade from midterm, final exam grades and homework grade
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous content
        hw.clear();
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next
        in.clear();
    }

    return in;
}

istream& read(istream& is, Student_info& s) {
    double midterm, final;
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> midterm >> final;

    vector<double> homework;
    read_hw(is, homework);
    // compute the student's final grade
    if (cin)
        s.finalGrade = grade(midterm, final, median(homework));

    return is;
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

    for(vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
        
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ')
             << ": "
             << students[i].finalGrade
             << endl;
    }
}