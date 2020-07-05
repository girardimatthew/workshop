#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "split.h"
#include "crossref.h"

using std::string;      using std::endl;
using std::map;         using std::vector;
using std::cin;         using std::istream;
using std::cout;        using std::max;
using std::pair;

int main() {
    my_ostream_iterator<pair<string, vector<int> > > out_it(cout, " ");
    xref(cin, split, out_it);
    return 0;
}