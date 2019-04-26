#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main ()
{
  int i;
  char buffer[30];
  printf ("Enter a number: ");
  fgets (buffer, 30, stdin);
  i = atoi (buffer);
  printf ("The value entered is %d.\n",i);
  return 0;
}
