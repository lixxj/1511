#include <stdio.h>

int main()
{
   double farenheit, celsius;
   // ask for a number
   printf("Enter first number: ");
   // read the number
   if (scanf("%lf", &farenheit) == 0) {
      printf("Not a number\n");
      return 1;
   }
  
   //print celsius temp
   celsius = 5.0/9.0 * (farenheit - 32); 
   printf("%5.0lf F = %5.1lf C\n", farenheit, celsius);
   return 0;
}
