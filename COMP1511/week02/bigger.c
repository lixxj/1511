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
   // if first > second
   if (first > second) {
      printf("First number is bigger\n");
   }
   // if first < second
   else if (first < second) {
      printf("Second number is bigger\n");
   }
   // if first = second
   else {
      printf("Numbers are equal\n");
   }
   return 0;
}
