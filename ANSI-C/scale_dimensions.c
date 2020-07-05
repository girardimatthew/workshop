//another example of variable parameters
//passing by reference

#include <stdio.h>

int main();
void scale_dimensions(int *, int *);

int main() {
    int height = 4;
    int width = 5;
    
    scale_dimensions(&height, &width);
    
    printf("Scaled height: %d\n", height);
    printf("Scaled width: %d\n", width);
}

void scale_dimensions(int *hp, int *wp) {
    int hscale = 3;
    int wscale = 5;
    
    *hp = *hp * hscale;
    *wp = *wp * wscale;
}
