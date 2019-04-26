//Read 3 numbers and indicate whether they can be the sides of a triangle.
//Written by XJ Li


#include <stdio.h>

int main(void)
{
    printf("Please enter three numbers: ");

	double a, b, c;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	
	if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
	printf("not a triangle\n");
	}
	else {
	printf("triangle\n");
	}
	
	return 0;
}
