/*In this exercise you will use a loop to print a countdown from 10 to 0. 
Start by creating a file called countdown.c in your week 4 directory, and copying the above code. 
Modify this code so that the loop counts down from 10 until 0.*/

#include <stdio.h>

int main(void) {
    int counter = 10; 
    
    while (counter >= 0) { 
        printf("%d\n", counter); // print counter
        counter = counter - 1; // increment counter
    }
    return 0;
}
