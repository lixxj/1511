// Written by XJ LI

#include <stdio.h>
#include <stdlib.h>

int Do_I_have_this_card(int *cards_in_hand, int number_of_cards_in_hand, int target_number);

#define YES                   1
#define NO                    0

int main(void) {
    int input[10000];
    int i1 = 0;
    while (scanf("%d", &input[i1]) == 1) {
        i1++;
    }
    
    int largest = 0;
    int i2 = 0;
    while (i2 < i1) {
        if (input[i2] > largest) {
            largest = input[i2];
        }
        i2++;
    }                                                                               
    
    int i3 = 1;
    while (i3 < largest) {
        if (Do_I_have_this_card(input, i1, i3) == NO) {
            printf("%d ", i3);
        }
        i3++;
    }
    printf("\n");
    
    return 0;
}


int Do_I_have_this_card(int *cards_in_hand, int number_of_cards_in_hand, int target_number) {
    int numbers_in_array = NO;
    int index_for_array = 0;
    while (index_for_array < number_of_cards_in_hand) {
        if (cards_in_hand[index_for_array] == target_number) {
            numbers_in_array = YES;
        }
        index_for_array++;
    }
    
    return numbers_in_array;
}
