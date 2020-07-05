#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int i;
    double *p;
    double balance[5];
    
    p = balance;

    /* set the seed */
    srand((unsigned)time(NULL));
    
    /* init array */
    for (i=0; i<5; ++i) {
        balance[i] = rand();
        printf("balance[%d]: %f\n", i, balance[i]);
    }
    
    /* output each array element's value */
    printf("Array values using pointers\n");
    
    for (i=0; i<5; ++i) {
        printf("*(p + %d) : %f\n", i, *(p + i));
    }
    
    printf("Array values using balance as address\n");
    
    for (i=0; i<5; ++i) {
        printf("*(balance + %d) : %f\n", i, *(balance + i));
    }

    return 0;
}
