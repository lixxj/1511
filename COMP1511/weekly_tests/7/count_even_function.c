#include <stdio.h>
#include <stdlib.h>

// return the number of even values in an array.
int count_even(int length, int array[]) {
    int count = 0;
    int i = 0;
    while (i < length) {
        if (array[i] % 2 == 0) {
            count++;
        }
        i++;
    }
    return count;
}
    
# define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {16, 7, 8, 12, 13, 19, 21, 12};

    int result = count_even(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
