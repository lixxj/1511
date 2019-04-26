/*Reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of an "X".

You can assume n is odd and >= 5.

Make your program match the examples below exactly.

You are not permitted to use an array in this exercise.*/
//Written by XJ Li.

#include <stdio.h>

int main(void) {
    int number;
    int row, column;

    printf("Enter size: ");
    scanf("%d", &number);

    row = 1;
    while (row <= number) {
        column = 1;
        
        while (column <= number) {
        if(column == row || column == (number - row + 1)) { 
        printf("*");}
        else { 
        printf("-");}
            
        column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;
}
