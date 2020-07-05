#include <stdio.h>
#include <vector>
#include "../Str/Str_c.h"

using std::vector;
using std::max;

Str::size_type width(const vector<Str>& v) {
    
    Str::size_type maxlen = 0;
    for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    
    return maxlen;
}
