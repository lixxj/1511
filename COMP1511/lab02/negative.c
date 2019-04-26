//"Don't be so negative!"
//if they entered a negative number. If the number is positive, the program should print "You have entered a positive number." If the user enters the number 0, the program should print "You have entered zero."
//XJ

#include <stdio.h>

int main(void)
{
    int number;
    
    scanf("%d", &number);
    if ( number > 0 ) {    
        printf("You have entered a positive number.\n");
    }
    else if ( number < 0 ) {
        printf( "Don't be so negative!\n");
    }
    else {
        printf( "You have entered zero.\n");
    }
    return 0;
}
