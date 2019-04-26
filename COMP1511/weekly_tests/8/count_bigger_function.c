// Written by XJ LI


#include <stdio.h>

// return the number of "bigger" values in an array (i.e. larger than 99
// or smaller than -99).
int count_bigger(int length, int array[]) {
    int index = 0;
    int count = 0;
    while (index < length) {
        if (array[index] > 99 || array[index] < -99) {
            count++;
        }
        index++;
    }
    return count;
}

// This is a simple main function which could be used
// to test your count_bigger function.
#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
