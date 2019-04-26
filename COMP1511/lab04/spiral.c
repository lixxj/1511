/*Reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of a spiral.

You can assume n is odd and >= 5.

You are only permitted to use C language features covered in weeks 1-3 lectures. In particular, you are not permitted to use array(s).

Make your program match the examples below exactly.

You are not permitted to use an array in this exercise.*/
//Written by XJ Li.


#include <stdio.h>

int main(void) {

    
    int number;
    int row = 1, column, l = 1;

    printf("Enter size: ");
    scanf("%d", &number);
    
    while (l <= number) {printf("*"); l = l + 1;}printf("\n");
    
    
    while (row <= number - 1) {
        column = 1;
        
        while (column <= number) {
        
        if(column >= row  && column < number - row + 1 && row <= 0.5*(number - 1)) { if(row % 2 != 0){printf("-");}
        else{printf("*");}                     }
        
        else if(column > (number - 1 - row)  && column < 2 + row && row > 0.5*(number - 1)){ if(row % 2 != 0){printf("-");}
        else{printf("*");}    
        }
            
        else if(column <= 0.5*(number-3)  && row >column&& row < number - column){ if(column % 2 != 0){printf("*");}
        else{printf("-");}    
        }
        
        else if(column >= 0.5*(number+3)  && row > 0&& row < number - 2 + 1){ if(column % 2 != 0){printf("*");}
        else{printf("-");}    
        }
        
        column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;
}


/* 
----------------*
***************-*
*-------------*-*
*-***********-*-*
*-*---------*-*-*
*-*-*******-*-*-*
*-*-*-----*-*-*-*
*-*-*-***-*-*-*-*
*-*-*-*---*-*-*-*
*-*-*-*****-*-*-*
*-*-*-------*-*-*
*-*-*********-*-*
*-*-----------*-*
*-*************-*
*---------------*
*****************    */


