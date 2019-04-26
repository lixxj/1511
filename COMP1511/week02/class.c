#include <stdio.h>

int main()
{
   int x;
   printf("Enter a number: ");
   scanf("%d", &x);
   
   if (x > 0) {
      if (x > 100) {
         printf("big ");
      }
      else {
         printf("small ");
      }
      printf("and positive\n");
   }
   else if (x < 0) {
      if (x < -100) {
         printf("big");
      }
      else {
         printf("small");
      }
      printf(" and negative\n");
   }
   else {
      printf("zero\n");
   }
   return 0;
}
