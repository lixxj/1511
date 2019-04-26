/*You are not permitted to use if statements.

You are not permitted to use loops (e.g. while).

You are not permitted to call functions other than printf and scanf. For example, you are not permitted to use functions from the math library.

You are not permitted to use printf inside expressions - you can only use printf as a statement (the way it has been used in lectures).

You can use printf to print the value of an expression, in other words you can have an expression inside printf.

You are only permitted to use parts of C covered in the weeks 1 and 2 lectures. For example, you are not permitted to use the ternary ?: operator. 

You are not permitted to define functions.

Hint : return 1 when correct 
       return 0 when wrong
*/


#include <stdio.h>

int main(void)
{
    int x, y, z;

    printf("Enter integer: ");
    printf("Enter integer: ");
    printf("Enter integer: ");

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    printf("The integers in order are: %d %d %d\n", x * ((x <= y) && (x <= z)) + y * ((y < x) && (y <= z)) + z * ((z < x) && (z < y)), 
    
    x * (((x <= y) && (x >= z)) || ((x >= y) && (x <= z))) + y * (((y < x) && (y >= z)) || ((y > x) && (y <= z))) + z * (((z < x) && (z > y)) || ((z > x) && (z < y))), 
    
    x * ((x >= y) && (x >= z)) + y * ((y > x) && (y >= z)) + z * ((z > x) && (z > y))); 
    
    return 0;
}

