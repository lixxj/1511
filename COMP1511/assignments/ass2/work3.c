#include <stdio.h>
#include <assert.h>

// THE GIVEN #defines

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

int Do_I_have_this_card(int *cards_in_hand, int number_of_cards_in_hand, int target_number);
int units_digit_of(int target_number);
int tens_digit_of(int target_number);
int Do_I_have_same_tens_digit_cards(int *cards_in_hand, int number_of_cards_in_hand, int target_number);
void read_cards(int how_many_cards, int *cards);

int main(void) {
    int cards_in_hand[5] = {0};
    int a = Do_I_have_this_card(cards_in_hand, 5, 46);
    printf("a = %d\n", a);

    return 0;
}

int Do_I_have_this_card(int *cards_in_hand, int number_of_cards_in_hand, int target_number) {
    int numbers_in_array = NO;
    int index_for_array = START_OF_ARRAY;
    while (index_for_array < number_of_cards_in_hand) {
        if (cards_in_hand[index_for_array] == target_number) {
            numbers_in_array = YES;
        }
        index_for_array++;
    }
    
    return numbers_in_array;
}
