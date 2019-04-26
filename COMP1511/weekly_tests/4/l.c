// reads an integer n from standard input. and prints a pattern of asterisks in the shape of an "L".
// You can assume n is positive.


#include <stdio.h>

int main(void) {
    int number;
    int row, column;

    // Obtain input
    printf("Enter size: ");
    scanf("%d", &number);

    row = 1;
    while (row < number) {
        printf("*\n");
        row = row + 1;
    }
    
    
    if (row == number) {
        column = 1;
        while (column <= number) {
            printf("*");
            column = column + 1;
        }
        printf("\n");
    }

    return 0;
}
