#include <stdio.h>

int main()
{
   int first, second;
   // ask for a number
   printf("Enter first number: ");
   // read the number
   if (scanf("%d", &first) == 0) {
      printf("Not a number\n");
      return 1;
   }
   // ask for another number
   printf("Enter second number: ");
   // read the other number
   if (scanf("%d", &second) == 0) {
      printf("Not a number\n");
      return 1;
   }
   //print the sum of the two numbers
   printf("%d + %d = %d\n", first, second, first+second);
   return 0;
}
