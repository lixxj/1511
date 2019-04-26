/*Read in a size and display a Danish Flag of that size using the following algorithm and the # character.

The Danish Flag is made up of 6 blocks. It is 3 blocks wide, and 2 blocks high. To display it using empty spaces and the character #, we will read in a value called size. Each block will be 3 times size wide, and 2 times size high.

In the top left block, the right column and bottom row will be empty spaces.
In the top middle block, the left column and bottom row will be empty spaces.
In the top right block, the bottom row will be empty spaces.
In the bottom left block, the right column and top row will be empty spaces.
In the bottom middle block, the left column and top row will be empty spaces.
In the bottom left block, the top row will be empty spaces.

Every other position will be the # character.*/
//Written by XJ Li.

#include <stdio.h>

int main(void) {
    int number;
    int row = 1, column;

    
    printf("Enter the flag size: ");
    scanf("%d", &number);

    int m = 9 * number;
    int n = 4 * number;
    
    while (row <= n) {
        column = 1;
        while (column <= m) {
            if (row <= ((2 * number) - 1) || row > ((2 * number) + 1)) {
                if (column == 3 * number || column == (3 * number) + 1) {
                    printf(" ");
                } else {
                    printf("#");
                }
            } else if (row == (2 * number) || row == ((2 * number) + 1)) {
                printf(" ");
            } else {
                printf("#");
            }
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;
}
