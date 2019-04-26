#include <stdio.h>
int tens_digit_of(int target_number);

int tens_digit_of(int target_number) {
    int digit2 = (target_number - target_number % 10) / 10;
    
    return digit2;
}


int main (void) {
    int array[1000];
    int t = 0;
    while (scanf("%d", &array[t]) != 0) {
        t++;
    }
    int target_tens_digit;
    printf("target_tens_digit:\n");
    scanf("%d", &target_tens_digit);
    int want_which;
    printf("want_which:\n");
    scanf("%d", &want_which);
    int same_digit1_array[t];
    int index1 = 0;
    int index2 = 0;
    while (index1 < t) {
        if (tens_digit_of(array[index1]) == target_tens_digit) {
            same_digit1_array[index2] = array[index1];
            index2++;
        }
        index1++;
    }
    int a;
    int i, j;
    for (i = 0; i < index2; ++i) {
        for (j = i + 1; j < index2; ++j) {
            if (same_digit1_array[i] < same_digit1_array[j]) {
                a = same_digit1_array[i];
                same_digit1_array[i] = same_digit1_array[j];
                same_digit1_array[j] = a;
            }
        }
    }
    printf("The numbers arranged in descending order are given below\n");
 
        for (i = 0; i < index2; ++i) 
        {
            printf("%d\n", same_digit1_array[i]);
        }
    
    printf("smallest is %d\n", same_digit1_array[index2 - 1]);
    
    
    return 0;
}
