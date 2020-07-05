#include "extract_fails.h"
#include "fgrade.h"
#include "Student_info.h"
#include <vector>

using std::vector;

// version 3: iterators but no indexing; still slow
vector<Student_info> extract_fails(vector<Student_info>& students) {
    
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    
    return fail;
}
