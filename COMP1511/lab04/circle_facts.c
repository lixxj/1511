// Alex Linker 2017-08-13
// This program prints out facts about a circle given its radius,
// using functions.
//Corrected by XJ Li.

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);
    
    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));
    
    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    return M_PI * radius * radius;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    return M_PI * 2* radius;
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    return 2 * radius;
}
