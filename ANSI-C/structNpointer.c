#include <stdio.h>

struct xampl {
    int x;
};

int main() {
    struct xampl structure;
    struct xampl *ptr;
    
    structure.x = 12;
    ptr = &structure;
    
    printf("%d\n", ptr->x);         //get whatever is at that memory address
}
