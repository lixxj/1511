// Written by XJ LI
#include <stdio.h>

int common_elements(int length, int source1[length], int source2[length], int destination[length]);

int main(void) {
    int length = 5;
    int source1[5] = {1, 2, 3, 2, 1};
    int source2[5] = {1, 2, 3, 4, 5};
    int destination[5] = {0};
    int c = common_elements(length, source1, source2, destination);
    printf("%d\n", c);
    int i = 0;
    while (i < c) {
        printf("%d,", destination[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}


int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int count = 0;
    int index1 = 0;
    int index2 = 0;
    while (index1 < length) {
        int index2 = 0;
        while (index2 < length) {
            if (source1[index1] == source2[index2]) {
                destination[count] = source1[index1];
                count++;
                break;
            }
            index2++;
        }
        index1++;
    }
    
    return count;
}


