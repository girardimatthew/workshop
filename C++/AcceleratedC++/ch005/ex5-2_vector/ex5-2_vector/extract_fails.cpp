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

#include <vector>

using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students) {
    
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);          // dereference the iterator the get the element
            iter = students.erase(iter);    
        } else
            ++iter;
    }
    
    return fail;
}
