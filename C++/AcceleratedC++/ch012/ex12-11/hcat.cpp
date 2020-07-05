#include <iostream>
#include <stdio.h>
#include "hcat.h"
#include "width.h"
#include <vector>

#include "../Str/Str_c.h"

/* =================================== 
Hello World!

********** **********
* Hello  * * Hello  *
* World! * * World! *
********** **********

********** **********
********** *********** Hello  * * Hello  *
********** *********** Hello  * * Hello  ** World! * * World! *
********** *********** Hello  * * Hello  ** World! * * World! *********** **********

=================================== */

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right) {
    
    vector<Str> ret;
    
    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<Str>::size_type i = 0, j = 0;
    
    // ex5-8: define s outside the scope of the while?
    Str s;
    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new string to hold characters from both pictures
        // string s;
        // 
        // defining s outside the scope of the while loop
        // won't affect the output since each loop
        // s = left[i++];
        
        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        //std::cout << s << std::endl;
        // pad to full width
        s += Str(width1 - s.size(), ' ');
        //std::cout << s << std::endl;
        
        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
        //std::cout << s << std::endl;
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
