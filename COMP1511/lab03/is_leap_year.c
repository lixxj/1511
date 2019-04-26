//reads a year and then prints whether that year is a leap year.
//XJ

#include <stdio.h>


int main(void)
{
   	printf("Enter year: ");
	int year;
	scanf("%d", &year);
	
	


	printf("%d", year);
	
	if ((year % 4 != 0))
	{printf("is not a leap year.\n");}
	
	else if((year % 100 != 0))
	{printf(" is a leap year.\n");}

	else if((year % 400 != 0))
	{printf(" is not a leap year.\n");}

	else 
	{printf(" is a leap year.\n");}

        
	return 0;
}
//if (year is not divisible by 4) then (it is a common year)
//else if (year is not divisible by 100) then (it is a leap year)
//else if (year is not divisible by 400) then (it is a common year)
//else (it is a leap year)
