#include <stdio.h>
#include <stdlib.h>

int main(void) {
int length = 0;
printf("length?\n");
scanf("%d", &length);
int *a;
a = (int*) malloc(length * sizeof(int));
printf("things in the array?\n");
for (int i = 0; i < length; i++)
{
scanf("%d", &a[i]);
}
printf("old array is\n");
for (int i = 0; i < length; i++)
{
printf("%d, ", a[i]);
}
printf("new array is\n");

for (int i = 0; i < length - 1; i++)
{
for (int j = i + 1; j < length; )
{
if (a[i] == a[j])
{
for (int k = j; k < length - 1; k++)
{
a[k] = a[k + 1];
}
length--;

}
else
{
j++;
}
}
}
for (int i = 0; i < length; i++)
{
printf("%d, ", a[i]);
}
}
