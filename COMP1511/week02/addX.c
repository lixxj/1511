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
   printf("%d + %d = %d\n", first, second, first+second);
   return 0;
}
