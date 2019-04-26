#include <stdio.h>
#include <stdlib.h>

double read(void);

int main(void) {
	double a;
	a = read();
	printf("%lf\n", a);
	
	return 0;
}

double read(void) {
    double d;
    double a = scanf("%lf", &d);
    if (a != 1) {
        fprintf(stderr, "Error\n");
        exit(1);
    }
    
    return d;
}


