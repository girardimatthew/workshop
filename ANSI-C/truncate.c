#include <stdio.h>

int main() {
    int *int_p;
    float *float_p;
    
    int my_int = 17;
    float my_float = 23.5;
    
    int_p = &my_int;
    float_p = &my_float;
    
    *int_p = *float_p;
    
    printf("%d\n", *int_p);
}
