#include <stdio.h>

int main() {
    int a,b,x=10,y=10;
    int i, ai, bi;
    
    a = ++x;
    b = y++;
    
    printf("a:%d, b:%d, x:%d, y:%d\n", a, b, x, y);
    
    x = 0;
    y = x;
    /* pre-increment */
    printf("--- Pre-increment ---\n");
    while (y<5) {
        printf("y:%d, x:%d\n", y, x);
        y = ++x;
    }
    printf("\n");
    
    x = 0;
    y = x;
    /* post-increment */
    printf("--- Post-increment ---\n");
    while (y<5) {
        printf("y:%d, x:%d\n", y, x);
        y = x++;
    }
    printf("\n");
}
