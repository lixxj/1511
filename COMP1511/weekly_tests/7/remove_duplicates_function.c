#include <stdio.h>
#include <stdlib.h>

int remove_duplicates(int length, int source[length], int destination[length]);

int main(void) {
    return 0;
}

int remove_duplicates(int length, int source[length], int destination[length]) {
    int z = 0;
    int dest[length];
    while (z < length) {
        dest[z] = source[z];
        z++;
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; ) {
            if (dest[i] == dest[j]) {
                for (int k = j; k < length - 1; k++) {
                    dest[k] = dest[k + 1];
                }
                length--;
            }
            else {
                j++;
            }
        }
    }
    int y = 0;
    while (y < length) {
        destination[y] = dest[y];
        y++;
    }
    return length;
}
