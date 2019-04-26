//reads a year and then uses a function to calculate whether that year is a leap year


#include <stdio.h>


int isLeapYear(int year){
	if ((year % 4 != 0))
	{return 0;}
	
	else if((year % 100 != 0))
	{return 1;}

	else if((year % 400 != 0))
	{return 0;}

	else 
	{return 1;}
	
}

int main(void)
{
   	printf("Enter year: ");
	int year;
	scanf("%d", &year);
	printf("%d", year);
	if (isLeapYear(year) == 0)
	{printf(" is not a leap year.\n");}
	else
	{printf(" is a leap year.\n");}
	return 0;
}



