// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

int Student_info::default_constructor_calls;
int Student_info::custom_constructor_calls;
int Student_info::stream_constructor_calls;
int Student_info::copy_constructor_calls;
int Student_info::assignment_calls;
int Student_info::destructor_calls;

Student_info::Student_info():
    n("default_name"),
    midterm(0), 
    final(0), 
    final_grade(0),
    pass(false) { 
        ++default_constructor_calls;
    }

Student_info::Student_info(const std::string& name,
                           const int& md,
                           const int& f,
                           const int& fg,
                           const bool& p) {
    ++custom_constructor_calls;

    n = name;
    midterm = md;
    final = f;
    final_grade = fg;
    pass = p;

}

Student_info::Student_info(istream& is) {
    ++stream_constructor_calls;
    read(is);
}

Student_info::Student_info(const Student_info& student_info) {
    ++copy_constructor_calls;
 
    n = student_info.n;
    midterm = student_info.midterm;
    final = student_info.final;
    final_grade = student_info.final_grade;
    pass = student_info.pass;
}

Student_info& Student_info::operator=(const Student_info& rhs) {
    ++assignment_calls;

    if (&rhs != this) {
        n = rhs.n;
        midterm = rhs.midterm;
        final = rhs.final;
        final_grade = rhs.final_grade;
        pass = rhs.pass;
    }

    return *this;
}

Student_info::~Student_info() {
    ++destructor_calls;
}

double Student_info::grade() const { 
    return final_grade;
}

std::string Student_info::pass_or_fail() const {
    return pass ? "P ✅ " : "F ❌ ";
}

std::string Student_info::letter() const { 
    return lgrade;
}

// not constant objects can't access functions that are not defined as constant
bool compare(Student_info& x, Student_info& y) {
    return x.grade() > y.grade();
}

istream& Student_info::read(istream& in) {
    // read and store the student's name and midterm and final exam grades
    const double minimum_score = 60.0;
    in >> n >> midterm >> final;
    final_grade = ::grade(midterm, final);
    pass = final_grade >= minimum_score;
    lgrade = ::letter_grade(final_grade);
    return in;
}

void Student_info::reset_class_info() {
    default_constructor_calls = 0;
    custom_constructor_calls = 0;
    stream_constructor_calls = 0;
    copy_constructor_calls = 0;
    assignment_calls = 0;
    destructor_calls = 0;
}

std::ostream& Student_info::print_class_info(std::ostream& os) {
    os << "======= printing class info =================================================" << std::endl;
    os << default_constructor_calls << '\t' << "default constructor calls" << std::endl;
    os << custom_constructor_calls << '\t' << "custom constructor calls" << std::endl;
    os << stream_constructor_calls << '\t' << "stream constructor calls" << std::endl;
    os << copy_constructor_calls << '\t' << "copy constructor calls" << std::endl;
    os << assignment_calls << '\t' << "assignment calls" << std::endl;
    os << destructor_calls << '\t' << "destructor calls" << std::endl;
    os << "=============================================================================" << std::endl;
    return os;
}