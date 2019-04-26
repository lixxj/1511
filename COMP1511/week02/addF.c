#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void printSum(int, int);

int main()
{
   int first, second;
   first = getNumber("Enter first number");
   second = getNumber("Enter second number");
   printSum(first,second);
   return 0;
}

void printSum(int x, int y)
{
   printf("%d + %d = %d\n", x, y, x+y);
}
