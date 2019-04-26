



#include <stdio.h>

int main(void) {
    int number;
    int row, column;

    // Obtain input
    printf("Enter size: ");
    scanf("%d", &number);

    row = 1;
    while(row < number) {
        column = 1;
        while (column <= number) {
            if(column == 1 || column == row)
            {printf("*");}
            else {printf(" ");}
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
    if(row == number) {
        column = 1;
        while (column <= number) {
            printf("*");
            column = column + 1;
        }
        printf("\n");
    }
    
    return 0;
}
