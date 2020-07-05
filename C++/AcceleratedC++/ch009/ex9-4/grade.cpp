#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"

using std::domain_error;
using std::vector;

// compute a student's overall grade from midterm, final exam grades and homework grade
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw) {

    // ex9-4: goal is to avoid the exception altogether.
    // However I think having no exception here forces
    // the programmer to use a unwritten rule
    // before using grade(double, double, vector<double>)
    // you need to call the valid() func
    // if (hw.size() == 0)
    //     throw domain_error("Error! - student has done no homework.");
    
    return grade(midterm, final, median(hw));
}