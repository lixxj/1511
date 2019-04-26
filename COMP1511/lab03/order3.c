//using if statements (no loops) that reads 3 integers and prints them from smallest to largest
//XJ

#include <stdio.h>

int main(void)
{
    
    	int X;
    	int Y;
	    int Z;
	
    	printf("Enter integer: ");
   	    scanf("%d", &X);
    	printf("Enter integer: ");
    	scanf("%d", &Y);
	    printf("Enter integer: ");
	    scanf("%d", &Z);
    	
    	if (X >= Y && X >= Z && Y >= Z){
       	printf("The integers in order are: %d %d %d\n", Z, Y, X);}
    	else if (X >= Z && Z >= Y && X >= Y){
       	printf("The integers in order are: %d %d %d\n", Y, Z, X);}
    	else if (Z >= Y && Z >= X && Y >= X){
       	printf("The integers in order are: %d %d %d\n", X, Y, Z);}
	    else if (Z >= X && Z >= Y && X >= Y){
       	printf("The integers in order are: %d %d %d\n", Y, X, Z);}
    	else if (Y >= X && Y >= Z && X >= Z){
       	printf("The integers in order are: %d %d %d\n", Z, X, Y);}
	    else if (Y >= Z && Y >= X && Z >= X){
	    printf("The integers in order are: %d %d %d\n", X, Z, Y);}
    	
	    return 0;
}


