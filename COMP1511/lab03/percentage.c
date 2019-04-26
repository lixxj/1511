//calculate the marks that a student got in an exam.

//Your program should scan in two integers: the total number of marks in the exam, and how many marks the student was awarded.

//It should then print out what mark they got in the exam, i.e. what percentage of the marks the student was awarded for that exam, with no decimal places.

#include <stdio.h>


int main(void)
{   double X;
	double Y;
   	printf("Enter the total number of marks in the exam: ");
   	    scanf("%lf", &X);
	printf("Enter the number of marks the student was awarded: ");
	    scanf("%lf", &Y);
	
	
	
	    double Z = Y / X;
	    double M = 100 * Z;





	printf("The student scored %.0lf", M);
	printf("%%");
	printf(" in this exam.\n");

	return 0;
}
