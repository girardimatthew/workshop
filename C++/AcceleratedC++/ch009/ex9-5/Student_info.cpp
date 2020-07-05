// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

Student_info::Student_info(): midterm(0), final(0), final_grade(0) { }

Student_info::Student_info(istream& is) { 
    read(is);
}

double Student_info::grade() const { 
    return final_grade;
}

std::string Student_info::pass_or_fail() const {
    return final_grade > 60.0 ? "P ✅ " : "F ❌ ";
}

// not constant objects can't access functions that are not defined as constant
bool compare(Student_info& x, Student_info& y) {
    return x.name() < y.name();
}

istream& Student_info::read(istream& in) {
    // read and store the student's name and midterm and final exam grades
    in >> n >> midterm >> final;
    final_grade = ::grade(midterm, final);
    return in;
}