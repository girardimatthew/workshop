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

#include <list>

using std::list;

// use list
list<Student_info> extract_fails(list<Student_info>& students) {
    
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    
    return fail;
}
