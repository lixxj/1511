#include <stdio.h>

int main()
{
   int first, second;
   // ask for a number
   printf("Enter two numbers: ");
   // read the number
   int n = scanf("%d %d", &first, &second);
   if (n != 2) {
      printf("Not two numbers\n");
      return 1;
   }
   //print the sum of the two numbers
   int sumsq = first*first + second*second;
   printf("%d^2 + %d^2 = %d\n", first, second, sumsq);
   return 0;
}
