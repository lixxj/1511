#include <stdio.h>
int main(void) {  
    int x;
    int a[6];

    x = 10;
    a[3 * 2] = 2 * 3 * 7;
    printf("%d\n", x);
}

while (index1 < N_TILES) {
        while(count1 < 1 && index2 < 4) {
            if(tiles1[index1] == tiles2[index2]) {
                count1 = count1 + 1;
            }
            index2 = index2 + 1;
        }        
        index1 = index1 + 1;    
        while(count2 < 1 && index2 < 4) {
            if(tiles1[index1] == tiles2[index2]) {
                count1 = count1 + 1;
            }
            index2 = index2 + 1;
        }        
        index1 = index1 + 1;     
        while(count3 < 1 && index2 < 4) {
            if(tiles1[index1] == tiles2[index2]) {
                count1 = count1 + 1;
            }
            index2 = index2 + 1;
        }        
        index1 = index1 + 1; 
        while(count4 < 1 && index2 < 4) {
            if(tiles1[index1] == tiles2[index2]) {
                count1 = count1 + 1;
            }
            index2 = index2 + 1;
        }        
        index1 = index1 + 1;
    
    }
