// function to cube a number

#include <stdio.h>

double cube(double x)
{
    double result;
    result = x * x * x;
    return result;
}

int main(void)
{
    double a, b;
    printf("42 cubed is %lf\n", cube(42.03));
    a = 2;
    b = cube(a);
    printf("2 cubed is %lf\n", b);
    return 0;
}
