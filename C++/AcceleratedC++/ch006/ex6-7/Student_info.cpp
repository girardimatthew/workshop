// source file for Student_info-related functions
#include "Student_info.h"
#include "median.h"
#include "grade.h"

using std::istream;
using std::vector;

void write_analysis(
    std::ostream& out, 
    const std::string& name, 
    double analysis_function(const Student_info& s), 
    const std::vector<Student_info>& did, 
    const std::vector<Student_info>& didnt) {
        
    out << name << ": median(did) = " << perform_analysis(analysis_function, did) << 
                   ", median(didnt) = " << perform_analysis(analysis_function, didnt) << std::endl;
}

double perform_analysis(double analysis_function(const Student_info& s), 
                        const vector<Student_info>& students) {

    std::vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), analysis_function);
    return median(grades);
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(std::istream& is, std::vector<Student_info>& v) {
    const int BUFFSIZE = 80;
    std::stringstream ss;
    char buff[BUFFSIZE];

    while (is.getline(buff, BUFFSIZE)) {
        ss << buff;
        Student_info student;
        read(ss, student);
        v.push_back(student);
    }
    return is;
}

istream& read(istream& is, Student_info& s) {

    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework); // read and store all the student's homework grades
    return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
    
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x) 
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}