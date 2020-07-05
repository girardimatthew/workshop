#ifndef extract_fails_h
#define extract_fails_h

#include <vector>
#include "Student_info.h"

std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::vector<Student_info> extract_didnt_all_hw(std::vector<Student_info>& students);
std::vector<Student_info> extract_best(std::vector<Student_info>& students);

std::vector<Student_info> extract(std::vector<Student_info>& students, 
                                  bool predicate(const Student_info&));

#endif /* extract_fails_h */
