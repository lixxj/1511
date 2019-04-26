
int getNumber(char *msg)
{
   int value;
   // ask for a number
   printf("%s: ", msg);
   // read the number
   if (scanf("%d", &value) == 1) {
      return value;
   }
   else {
      printf("Not a number\n");
      exit(1);
   }
}
