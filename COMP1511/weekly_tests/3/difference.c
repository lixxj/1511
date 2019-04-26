//Reads 2 integers and prints their difference.
//If they are equal it should print "equal".
//Written by XJ Li


#include <stdio.h>

int main(void)
{
	double a, b;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	
	double c = a - b;
	double d = b - a;
	
	if (a > b) {
	printf("%.0lf\n", c);
	}
	else if (a < b) {
	printf("%.0lf\n", d);
	}
	else {
	printf("equal\n");
	}
	
	return 0;
}
