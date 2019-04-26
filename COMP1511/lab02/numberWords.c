//Numbers to Words

//This program will ask for a number with the message Please enter an integer:.

//For numbers between 1 and 5, display the number as a word in the message You entered number.

//For numbers less than 1, display the message You entered a number less than one.

//For numbers greater than 5, display the message You entered a number greater than five.

//XJ

#include <stdio.h>

int main(void)
{
    printf("Please enter an integer: ");
    int N;
    scanf("%d", &N);
    if (N == 1){ printf("You entered one.\n");}
    else if (N == 2){ printf("You entered two.\n");}
    else if (N == 3){ printf("You entered three.\n");}
    else if (N == 4){ printf("You entered four.\n");}
    else if (N == 5){ printf("You entered five.\n");}
    else if (N < 1){ printf("You entered a number less than one.\n");}
    else { printf("You entered a number greater than five.\n");}
    return 0;
}
