#include "fgrade.h"
#include "grade.h"

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

// predicate to determine whether a student
// has a top grade
bool tgrade(const Student_info& s) {
    return !(grade(s) > 90);
}
