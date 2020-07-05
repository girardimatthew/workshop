// source file for Student_info-related functions
#include "Student_info.h"
#include "median.h"
#include "grade.h"

using std::istream;
using std::vector;

void write_analysis(
    std::ostream& out, 
    const std::string& name, 
    double analysis(const std::vector<Student_info>&), 
    const std::vector<Student_info>& did, 
    const std::vector<Student_info>& didnt) {
        
    out << name << "\n\t - median(did) = " << analysis(did) << 
                   "\n\t - median(didnt) = " << analysis(didnt) << std::endl;
    out << std::endl;
}

template <class Out, class In>
Out analysis(const vector<In>& vs, Out grade(const In& s)) {
    std::vector<Out> grades;
    transform(vs.begin(), vs.end(), back_inserter(grades), grade);
    return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {
    return analysis(students, optimistic_median);
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

double average_analysis(const vector<Student_info>& students) {
    return analysis(students, average_grade);
}

double median_analysis(const vector<Student_info>& students) {
    return analysis(students, grade_aux);
}

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
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