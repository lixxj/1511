#include <stdio.h>
#include <assert.h>

// THE GIVEN #defines
int units_digit_of(int target_number);
int tens_digit_of(int target_number);
#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2
#define ACTION_UNIT_TESTS     3

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// ADD EXTRA #defines HERE

#define START_OF_ARRAY        0
#define END_OF_ARRAY          9
#define YES                   1
#define NO                    0
int main(void) {
    int sum = 0;
    int target_number;
    printf("target_number\n");
    scanf("%d", &target_number);
    int digit2_of_target_number = tens_digit_of(target_number);
    int cards_in_hand[6];
    printf("6 cards\n");
    int y = 0;
    while(y < 6) {
        scanf("%d", &cards_in_hand[y]);
        y++;
    }
    int digit2_of_target_cards_in_hand[6];
    int index1 = START_OF_ARRAY;
    while (index1 < 6) {
        digit2_of_target_cards_in_hand[index1] = tens_digit_of(cards_in_hand[index1]);
        index1++;
    }
    int index2 = START_OF_ARRAY;
    while (index2 < 6) {
        if (digit2_of_target_cards_in_hand[index2] == digit2_of_target_number) {
            sum = sum + cards_in_hand[index2] - 10 * digit2_of_target_number;
        }
        index2++;
    }
    printf("sum = %d\n", sum);
    return 0;
}
int units_digit_of(int target_number) {
    int digit1 = target_number % 10;
    
    return digit1;
}

int tens_digit_of(int target_number) {
    int digit2 = (target_number - target_number % 10) / 10;
    
    return digit2;
}
