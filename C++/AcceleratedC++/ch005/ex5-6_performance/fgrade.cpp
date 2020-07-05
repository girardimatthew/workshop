#include "fgrade.h"
#include "grade.h"

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}
