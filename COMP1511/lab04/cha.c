#include <stdio.h>

int main(void) {
    int n;
    int row = 1, column;

    printf("How many boxes: ");
    scanf("%d", &n);
    int m = 4 * n - 1;

     while (row <= m) {
        int column = 1;
        while (column <= m) {
            
            
            if (column % 2 != 0 && row % 2 != 0) {
                printf("#"); }
           
            
            else if(row % 2 == 0 && column % 2 != 0) {
                if(row <= 2 * n) {if((column < row) || (column > (m + 1 - row))) {printf("#");}  else{printf(" ");}}
                else {if(row > 2 * n) {if(column < (m + 1 - row) || column > row) {printf("#");} else{printf(" ");}}}}
                
            
            else if(column % 2 == 0 && row % 2 != 0) {
                if(column <= 2 * n) {if((row < column) || (row > (m + 1 - column))) {printf("#");}  else{printf(" ");}}
                else {if(column > 2 * n) {if(row < (m + 1 - column) || row > column) {printf("#");} else{printf(" ");}}}}

            
           else {printf(" ");}
               
                
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
     }
  
    return 0;
}

//&& column % 2 != 0,&& row % 2 != 0
//if(column % 2 == 0 )
