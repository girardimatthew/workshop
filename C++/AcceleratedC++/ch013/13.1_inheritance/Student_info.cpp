// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;

Student_info::Student_info(): 
    midterm(0), 
    final(0), 
    final_grade(0),
    pass(false) 
    { }

Student_info::Student_info(double mt, double f, std::string name) {
    midterm = mt;
    final = f;
    n = name;
    
    final_grade = ::grade(midterm, final);
    pass = final_grade >= minimum_score;
}

Student_info::Student_info(istream& is) { 
    read(is);
}

double Student_info::grade() const { 
    return final_grade;
}

std::string Student_info::pass_or_fail() const {
    return pass ? "P ✅ " : "F ❌ ";
}

// not constant objects can't access functions that are not defined as constant
bool compare(Student_info& x, Student_info& y) {
    return x.grade() > y.grade();
}

istream& Student_info::read(istream& in) {
    // read and store the student's name and midterm and final exam grades
    in >> n >> midterm >> final;
    final_grade = ::grade(midterm, final);
    pass = final_grade >= minimum_score;
    return in;
}

Student_info::operator double() const {
    return final_grade;
}