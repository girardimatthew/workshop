//
//  extract_fails.cpp
//  ex5-0
//
//  Created by Matteo Girardi (MTGI) on 01/06/2019.
//  Copyright © 2019 Matteo Girardi (MTGI). All rights reserved.
//

#include "extract_fails.h"
#include "fgrade.h"
#include "Student_info.h"
#include "StudentInfoContainerType.h"
#include <list>
#include <vector>

using std::list;
using std::vector;

// version 4: use list instead of vector
StudentInfoContainerType extract_fails(StudentInfoContainerType& students) {
    
    StudentInfoContainerType fail;
    StudentInfoContainerType::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    
    return fail;
}
