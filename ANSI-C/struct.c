//basic object, x and y coordinates
#include <stdio.h>

int main() {
    //structure declaration and tag
    struct point{
        double x;                                   //members
        double y;
    };
    struct point pt = {10, 20};                     //a variable pt which is a structure of type struct point
    double dist, sqrt(double);
    printf("x: %f, y: %f\n", pt.x, pt.y);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("dist: %f\n", dist);
    //rappresentation of a rectangle
    struct rect {
        struct point pt1;
        struct point pt2;
    };
    struct rect screen = {1, 2, 3, 4};
    printf("pt1.x: %f, pt1.y: %f\n", screen.pt1.x, screen.pt1.y);
    printf("pt2.x: %f, pt2.y: %f\n", screen.pt2.x, screen.pt2.y);
    dist = sqrt((double)screen.pt1.x * screen.pt1.x + (double)screen.pt1.y * screen.pt1.y);
    printf("dist pt1: %f\n", dist);
    dist = sqrt((double)screen.pt2.x * screen.pt2.x + (double)screen.pt2.y * screen.pt2.y); 
    printf("dist pt2: %f\n", dist);
}
