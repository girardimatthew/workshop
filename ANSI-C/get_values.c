//variable parameters
//passing by reference

#include <stdio.h>

int main();
void get_values(int *, int *);

int main() {
    int num1, num2;
    get_values(&num1, &num2);

    printf("num1: %d, num2: %d\n", num1, num2);
    
    return 0;
}

void get_values(int *num_p1, int *num_p2) {
    *num_p1 = 10;
    *num_p2 = 20;
}
