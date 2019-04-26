// reads 3 integers and prints the middle integer.

// You are not permitted to use loops or arrays (use if statements).

// Written by XJ Li.


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
       	printf("Middle: %d\n", Y);}
    	else if (X >= Z && Z >= Y && X >= Y){
       	printf("Middle: %d\n", Z);}
    	else if (Z >= Y && Z >= X && Y >= X){
       	printf("Middle: %d\n", Y);}
	    else if (Z >= X && Z >= Y && X >= Y){
       	printf("Middle: %d\n", X);}
    	else if (Y >= X && Y >= Z && X >= Z){
       	printf("Middle: %d\n", X);}
	    else if (Y >= Z && Y >= X && Z >= X){
	    printf("Middle: %d\n", Z);}
    	
	    return 0;
}
