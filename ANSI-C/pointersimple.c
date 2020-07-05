#include <stdio.h>

int main() {
    int idx, x = 1, y = 2, z[10], num = 5;
    int *ip;                        //ip is a pointer to int
    // init z
    for (idx=0; idx < 10; idx++) {
        z[idx] = num*(idx+1);
        printf("z[%d]: %d, ", idx, z[idx]);
        if (idx==9) {
            printf("\n");
        }
    }
    
    printf("x: %d, y: %d\n", x, y);

    ip = &x;                        //ip now points to x
    printf("ip: %d\n", *ip);
    y = *ip;                        //y is now 1
    printf("y: %d\n", y);
    *ip = 0;                        //x is now 0
    printf("x: %d\n", x);
    for (idx=0; idx < 10; idx++) {                      
        ip = &z[idx];
        printf("ip now points to z[%d]: %d\n", idx, *ip);
    }
    
    //modify z[idx] contents
    num = 3;
    for (idx=0; idx < 10; idx++) {
        ip = &z[idx];
        *ip = num*(idx+1);
        printf("z[%d]: %d, ", idx, z[idx]);
        if (idx==9) {
            printf("\n");
        }
    }
    
    for (idx=0; idx < 10; idx++) {
        ip = &z[idx];
        *ip += 10;
        printf("z[%d]: %d, ", idx, z[idx]);
        if (idx==9) {
            printf("\n");
        }
    }

    for (idx=0; idx < 10; idx++) {
        ip = &x;
        printf("x: %d, ", ++(*ip));                     //pre-increment
        //printf("x: %d, ", (*ip)++);                   //post-increment
        if (idx==9) {
            printf("\n");
        }
    }
}
