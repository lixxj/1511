#include <stdio.h>

int main()
{
   int farenheit, celsius;
   // ask for a number
   printf("Enter first number: ");
   // read the number
   if (scanf("%d", &farenheit) == 0) {
      printf("Not a number\n");
      return 1;
   }
  
   //print celsius temp
   celsius = 5 * (farenheit - 32) / 9; 
   printf("%d F = %d C\n", farenheit, celsius);
   return 0;
}
