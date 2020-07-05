//
//  fgrade.cpp
//  ex5-0
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include "fgrade.h"
#include "grade.h"

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
    return grade(s) < 90;
}
