#include "grade.h"

// compute a student's overall grade from midterm, final exam grades and homework grade
double grade(double midterm, double final) {
    return (midterm + final) / 2.0;
}