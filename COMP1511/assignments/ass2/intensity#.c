// Assignment 2, COMP1511 18s1: Intensity
//
// Written by Xingjian Li (z5190719)

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

// EXTRA #defines

#define START                 0
#define END_OF_ARRAY          9

#define YES                   1
#define NO                    0

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);

// PROTOTYPES FOR YOUR FUNCTIONS 

int Do_I_have_this_card(int *cards_in_hand, 
                        int number_of_cards_in_hand,
                        int target_number);
int units_digit_of(int target_number);
int tens_digit_of(int target_number);
int Do_I_have_same_tens_digit_cards(int *cards_in_hand, 
                                    int number_of_cards_in_hand, 
                                    int target_number);
void read_cards(int how_many_cards, int *cards);
int do_they_have_a_same_tens_larger_one(int candidate, 
                                        int *previous_cards, 
                                        int number_of_previous_cards, 
                                        int *cards_in_hand, 
                                        int number_of_cards_in_hand);
int sum_of_units_digit_of_same_tens_digit(int *cards_in_hand, 
                                          int number_of_cards_in_hand, 
                                          int target_number);
int order_of_same_tens(int *array, int size, 
                       int target_tens_digit, 
                       int want_which);
int appropriate_play(int *cards_in_hand, int number_of_cards_in_hand, 
                     int *cards_played_in_round, 
                     int number_of_cards_played_in_round);                       
int smallest_same_tens_digit(int *array, int size, int target);  
int largest_same_tens_digit(int *array, int size, int target);
int second_smallest_same_tens_digit(int *array, int size, int target);                     
int how_many_same_tens_digit(int *array, int size, int target);
void test_Do_I_have_this_card(void);
void test_units_digit_of(void);
void test_tens_digit_of(void);
void test_Do_I_have_same_tens_digit_cards(void);
void test_sum_of_units_digit_of_same_tens_digit(void);
void test_smallest_same_tens_digit(void);
void test_second_smallest_same_tens_digit(void);
void test_smallest_same_tens_digit(void);
void test_how_many_same_tens_digit(void);

// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    } else {
        run_unit_tests();
    }

    return 0;
}

// Print out player name
void print_player_name(void) {
    // PLAYER NAME
    printf("OOOLD\n");

}

// Scan the received cards then choose and print out 3 abandoned cards
void choose_discards(void) {
    // READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int initial_card_index = START;
    int initial_card[N_CARDS_INITIAL_HAND];
    while (initial_card_index < N_CARDS_INITIAL_HAND) {
        scanf("%d", &initial_card[initial_card_index]);
        initial_card_index++;
    }
    // CHOOSE THREE CARDS YOU WISH TO DISCARD FROM YOUR HAND
    /* I create an array to represent discard cards,
       I use a special arrangement to accomodate
       the cards that meet the requirement.
       However, if there are more than one cards in the "discard" array,
       only the first one is the most important because of the special
       arrangement.
       For this reason, it's not appropriate to create loops sometime.*/
    int discard[N_CARDS];
    int choose_index = END_OF_ARRAY;
    int discard_index = START;
    while (choose_index >= START) {
        if (initial_card[choose_index] == 49) {
            discard[discard_index] = 49;
            discard_index++;
        }
        if (initial_card[choose_index] == 48) {
            discard[discard_index] = 48;
            discard_index++;
        }
        if (initial_card[choose_index] == 47) {
            if (Do_I_have_this_card
                (initial_card, N_CARDS_INITIAL_HAND, 40) == NO
                && Do_I_have_this_card
                (initial_card, N_CARDS_INITIAL_HAND, 41) == NO
                && Do_I_have_this_card
                (initial_card, N_CARDS_INITIAL_HAND, 42) == NO
                && Do_I_have_this_card
                (initial_card, N_CARDS_INITIAL_HAND, 43) == NO
                && Do_I_have_this_card
                (initial_card, N_CARDS_INITIAL_HAND, 44) == NO) {
            discard[discard_index] = 47;
            discard_index++;
            } 
        }
        if (initial_card[choose_index] == 39) {
            discard[discard_index] = 39;
            discard_index++;
        }
        if (initial_card[choose_index] == 38) {
            discard[discard_index] = 38;
            discard_index++;
        }
        if (initial_card[choose_index] == 37) {
            discard[discard_index] = 37;
            discard_index++;
        }
        if (initial_card[choose_index] == 36) {
            discard[discard_index] = 36;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {
        if (initial_card[choose_index] == 19) {
            discard[discard_index] = 19;
            discard_index++;
        }
        if (initial_card[choose_index] == 29) {
            discard[discard_index] = 29;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 18) {
            discard[discard_index] = 18;
            discard_index++;
        }
        if (initial_card[choose_index] == 28) {
            discard[discard_index] = 28;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {     
        if (initial_card[choose_index] == 35) {
            discard[discard_index] = 35;
            discard_index++;
        }
        if (initial_card[choose_index] == 17) {
            discard[discard_index] = 17;
            discard_index++;
        }
        if (initial_card[choose_index] == 27) {
            discard[discard_index] = 27;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 16) {
            discard[discard_index] = 16;
            discard_index++;
        }
        if (initial_card[choose_index] == 26) {
            discard[discard_index] = 26;
            discard_index++;
        }
        if (initial_card[choose_index] == 46) {
            discard[discard_index] = 46;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 34) {
            discard[discard_index] = 34;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 15) {
            discard[discard_index] = 15;
            discard_index++;
        }
        if (initial_card[choose_index] == 25) {
            discard[discard_index] = 25;
            discard_index++;
        }
        if (initial_card[choose_index] == 45) {
            discard[discard_index] = 45;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 33) {
            discard[discard_index] = 33;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 14) {
            discard[discard_index] = 14;
            discard_index++;
        }
        if (initial_card[choose_index] == 24) {
            discard[discard_index] = 24;
            discard_index++;
        }
        if (initial_card[choose_index] == 44) {
            discard[discard_index] = 44;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 13) {
            discard[discard_index] = 13;
            discard_index++;
        }
        if (initial_card[choose_index] == 23) {
            discard[discard_index] = 23;
            discard_index++;
        }
        if (initial_card[choose_index] == 43) {
            discard[discard_index] = 43;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 12) {
            discard[discard_index] = 12;
            discard_index++;
        }
        if (initial_card[choose_index] == 22) {
            discard[discard_index] = 22;
            discard_index++;
        }
        if (initial_card[choose_index] == 42) {
            discard[discard_index] = 42;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 11) {
            discard[discard_index] = 11;
            discard_index++;
        }
        if (initial_card[choose_index] == 21) {
            discard[discard_index] = 21;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 32) {
            discard[discard_index] = 32;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 42) {
            discard[discard_index] = 42;
            discard_index++;
        }
        choose_index--;
    }
    choose_index = END_OF_ARRAY;
    while (choose_index >= START) {    
        if (initial_card[choose_index] == 31) {
            discard[discard_index] = 31;
            discard_index++;
        }
        choose_index--;
    }
    // DISCARD THE THREE CARDS
    printf("%d %d %d\n", discard[START], 
           discard[START + 1], discard[START + 2]);

}

// Choose and print 1 card to play 
void choose_card_to_play(void) {
    // READ HOW MANY CARDS IN HAND
    int number_of_cards_in_hand;
    scanf("%d", &number_of_cards_in_hand);
    
    // READ HOW MANY CARDS HAVE ALREADY BEEN PLAYED IN THIS ROUND
    int number_of_cards_played_in_round;
    scanf("%d", &number_of_cards_played_in_round);
    
    // READ TABLE POSITION
    int table;
    scanf("%d", &table);
    
    // READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int cards_in_hand[N_CARDS_INITIAL_HAND];
    read_cards(number_of_cards_in_hand, cards_in_hand);
    
    // READ THE CARDS PLAYED THIS ROUND INTO AN ARRAY USING SCANF
    int cards_played_in_round[N_PLAYERS];
    read_cards(number_of_cards_played_in_round, cards_played_in_round);
    
    // READ THE CARDS PREVIOUSLY PLAYED INTO AN ARRAY USING SCANF
    int number_of_previous_cards = N_PLAYERS * (N_CARDS_INITIAL_HAND 
    - number_of_cards_in_hand);
    int previous_cards[N_CARDS];
    read_cards(number_of_previous_cards, previous_cards);
    
    // READ THE CARDS YOU DISCARDED AT THE START INTO AN ARRAY 
    int discard[N_CARDS_DISCARDED];
    read_cards(N_CARDS_DISCARDED, discard);
    
    // READ THE CARDS YOU RECEIVED AT THE START INTO AN ARRAY
    int receive[N_CARDS_DISCARDED];
    read_cards(N_CARDS_DISCARDED, receive);
    
    // CHOOSE A CARD YOU WISH TO PLAY FROM YOUR HAND
    int card[N_CARDS];
    int index_for_card = START;
    // If I am the first one to play in this round
    if (number_of_cards_played_in_round == NO) {
        // Calves played before
        if (Do_I_have_same_tens_digit_cards(previous_cards, 
            number_of_previous_cards, 30) == YES) {
            int candidate1 = 46;
            while (candidate1 <= 46 && candidate1 >= 40) {
                if (Do_I_have_this_card(cards_in_hand, 
                    number_of_cards_in_hand, candidate1) == YES) {
                    card[index_for_card] = candidate1;
                    index_for_card++;
                }
                candidate1--;
            }
            int candidate2 = 34;
            while (candidate2 <= 34 && candidate2 >= 30) {
                if (Do_I_have_this_card(cards_in_hand, 
                    number_of_cards_in_hand, candidate2) == YES) {
                    card[index_for_card] = candidate2;
                    index_for_card++;
                }
                candidate2--;
            }
            /* If the sum_of_units_digit_of_same_tens_digit in previous 
               is smaller, the sum_of_units_digit_of_same_tens_digit 
               remain is larger, so it's more likely to avoid winning*/
            // play 1X if sum of 2X is larger than 1X
            if (sum_of_units_digit_of_same_tens_digit(previous_cards,
                number_of_previous_cards, 20) >= 
                sum_of_units_digit_of_same_tens_digit(previous_cards, 
                number_of_previous_cards, 10)
                && Do_I_have_same_tens_digit_cards(cards_in_hand, 
                number_of_cards_in_hand, 10) == YES) {
                // If have more than one same digit cards
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10) > 1) {
                    card[index_for_card] = 
                    second_smallest_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10);
                    index_for_card++;
                }
                // Only have one same digit card
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10) == 1) {
                    card[index_for_card] = smallest_same_tens_digit
                    (cards_in_hand, number_of_cards_in_hand, 10);
                    index_for_card++;
                }
            } else if (sum_of_units_digit_of_same_tens_digit
                       (previous_cards, number_of_previous_cards, 20) < 
                       sum_of_units_digit_of_same_tens_digit(
                       previous_cards, number_of_previous_cards, 10)
                       && Do_I_have_same_tens_digit_cards
                       (cards_in_hand, number_of_cards_in_hand, 
                       20) == YES) {
                // If have more than one same digit cards
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20) > 1) {
                    card[index_for_card] = 
                    second_smallest_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20);
                    index_for_card++;
                }
                // Only have one same digit card
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20) == 1) {
                    card[index_for_card] = smallest_same_tens_digit
                    (cards_in_hand, number_of_cards_in_hand, 20);
                    index_for_card++;
                }
            } /* Sometimes the situation may not in the two "if"s above,
                 so I play the smallest card I have*/else {
                int oneX = 10;
                int twoX = 20;
                while (oneX >= 10 && oneX <= 19 && 
                       twoX >= 20 && twoX <= 29) {
                    if (Do_I_have_this_card(cards_in_hand, 
                        number_of_cards_in_hand, oneX) == YES) {
                        card[index_for_card] = oneX;
                        index_for_card++;
                    }
                    if (Do_I_have_this_card(cards_in_hand, 
                        number_of_cards_in_hand, twoX) == YES) {
                        card[index_for_card] = twoX;
                        index_for_card++;
                    }
                    oneX++;
                    twoX++;
                }
            }
            int candidate3 = 35;
            while (candidate3 <= 39 && candidate3 >= 35) {
                if (Do_I_have_this_card(cards_in_hand, 
                    number_of_cards_in_hand, candidate3) == YES) {
                    card[index_for_card] = candidate3;
                    index_for_card++;
                }
                candidate3++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 47) == YES) {
                    card[index_for_card] = 47;
                    index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 48) == YES) {
                    card[index_for_card] = 48;
                    index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 49) == YES) {
                    card[index_for_card] = 49;
                    index_for_card++;
            }
        }
        // no Calves played before
        if (Do_I_have_same_tens_digit_cards(previous_cards, 
            number_of_previous_cards, 30) == NO) {
            int candidate4 = 46;
            while (candidate4 <= 46 && candidate4 >= 40) {
                if (Do_I_have_this_card(cards_in_hand, 
                    number_of_cards_in_hand, candidate4) == YES) {
                    card[index_for_card] = candidate4;
                    index_for_card++;
                }
                candidate4--;
            }
            // play 1X if sum of 2X is larger than 1X
            if (sum_of_units_digit_of_same_tens_digit(
                previous_cards, number_of_previous_cards, 20) >= 
                sum_of_units_digit_of_same_tens_digit(
                previous_cards, number_of_previous_cards, 10)
                && Do_I_have_same_tens_digit_cards(
                cards_in_hand, number_of_cards_in_hand, 10) == YES) {
                // If have more than one same digit cards
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10) > 1) {
                    card[index_for_card] = 
                    second_smallest_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10);
                    index_for_card++;
                }
                // Only have one same digit card
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 10) == 1) {
                    card[index_for_card] = smallest_same_tens_digit
                    (cards_in_hand, number_of_cards_in_hand, 10);
                    index_for_card++;
                }    
            } // play 2X
            else if (sum_of_units_digit_of_same_tens_digit(
                     previous_cards, number_of_previous_cards, 20) < 
                     sum_of_units_digit_of_same_tens_digit(
                     previous_cards, number_of_previous_cards, 10)
                     && Do_I_have_same_tens_digit_cards(
                     cards_in_hand, number_of_cards_in_hand, 20) 
                     == YES) {
                // If have more than one same digit cards
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20) > 1) {
                    card[index_for_card] = 
                    second_smallest_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20);
                    index_for_card++;
                }
                // Only have one same digit card
                if (how_many_same_tens_digit(cards_in_hand, 
                    number_of_cards_in_hand, 20) == 1) {
                    card[index_for_card] = smallest_same_tens_digit
                    (cards_in_hand, number_of_cards_in_hand, 20);
                    index_for_card++;
                }
            } /* Sometimes the situation may not in the two "if"s above,
                 so I play the smallest card I have*/else {
                int oneX = 10;
                int twoX = 20;
                while (oneX >= 10 && oneX <= 19 && 
                       twoX >= 20 && twoX <= 29) {
                    if (Do_I_have_this_card(cards_in_hand, 
                        number_of_cards_in_hand, oneX) == YES) {
                        card[index_for_card] = oneX;
                        index_for_card++;
                    }
                    if (Do_I_have_this_card(cards_in_hand, 
                        number_of_cards_in_hand, twoX) == YES) {
                        card[index_for_card] = twoX;
                        index_for_card++;
                    }
                    oneX++;
                    twoX++;
                }
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 47) == YES) {
                    card[index_for_card] = 47;
                    index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 48) == YES) {
                    card[index_for_card] = 48;
                    index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 49) == YES) {
                    card[index_for_card] = 49;
                    index_for_card++;
            }
        }
    }
    // If I am not the first one to play in this round
    if (number_of_cards_played_in_round != NO) {
        // If I have same tens digit cards 
        if (Do_I_have_same_tens_digit_cards(cards_in_hand,
            number_of_cards_in_hand, 
            cards_played_in_round[START]) == YES) {
            // If have more than one same digit cards
            if (how_many_same_tens_digit(cards_in_hand, 
                number_of_cards_in_hand, 
                cards_played_in_round[START]) > 1) {
                card[index_for_card] = appropriate_play(cards_in_hand, 
                number_of_cards_in_hand, cards_played_in_round, 
                number_of_cards_played_in_round);
                index_for_card++;
            }
            // Only have one same digit card
            if (how_many_same_tens_digit(cards_in_hand, 
                number_of_cards_in_hand, 
                cards_played_in_round[START]) == 1) {
                card[index_for_card] = smallest_same_tens_digit
                (cards_in_hand, number_of_cards_in_hand, 
                cards_played_in_round[START]);
                index_for_card++;
            }
        } 
        // If I don't have same tens digit cards
        /* I use a special arrangement to accomodate
           the cards that meet the requirement.
           However, if therr're more than one cards in the "Play" array,
           only the first one is the most important because of the 
           special arrangement.
           For this reason, can not create loops sometime.*/
        if (Do_I_have_same_tens_digit_cards(cards_in_hand, 
            number_of_cards_in_hand, 
            cards_played_in_round[START]) == NO) {
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 47) == YES) {
                card[index_for_card] = 47;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 49) == YES) {
                card[index_for_card] = 49;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 48) == YES) {
                card[index_for_card] = 48;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 39) == YES) {
                card[index_for_card] = 39;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 38) == YES) {
                card[index_for_card] = 38;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 37) == YES) {
                card[index_for_card] = 37;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 36) == YES) {
                card[index_for_card] = 36;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 35) == YES) {
                card[index_for_card] = 35;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 29) == YES) {
                card[index_for_card] = 29;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 19) == YES) {
                card[index_for_card] = 19;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 28) == YES) {
                card[index_for_card] = 28;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 18) == YES) {
                card[index_for_card] = 18;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 27) == YES) {
                card[index_for_card] = 27;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 17) == YES) {
                card[index_for_card] = 17;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 26) == YES) {
                card[index_for_card] = 26;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 16) == YES) {
                card[index_for_card] = 16;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 34) == YES) {
                card[index_for_card] = 34;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 33) == YES) {
                card[index_for_card] = 33;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 25) == YES) {
                card[index_for_card] = 25;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 15) == YES) {
                card[index_for_card] = 15;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 46) == YES) {
                card[index_for_card] = 46;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 32) == YES) {
                card[index_for_card] = 32;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 24) == YES) {
                card[index_for_card] = 24;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 14) == YES) {
                card[index_for_card] = 14;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 23) == YES) {
                card[index_for_card] = 23;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 13) == YES) {
                card[index_for_card] = 13;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 45) == YES) {
                card[index_for_card] = 45;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 22) == YES) {
                card[index_for_card] = 22;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 12) == YES) {
                card[index_for_card] = 12;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 44) == YES) {
                card[index_for_card] = 44;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 21) == YES) {
                card[index_for_card] = 21;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 11) == YES) {
                card[index_for_card] = 11;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 43) == YES) {
                card[index_for_card] = 43;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 20) == YES) {
                card[index_for_card] = 20;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 10) == YES) {
                card[index_for_card] = 10;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 31) == YES) {
                card[index_for_card] = 31;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 42) == YES) {
                card[index_for_card] = 42;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 41) == YES) {
                card[index_for_card] = 41;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 30) == YES) {
                card[index_for_card] = 30;
                index_for_card++;
            }
            if (Do_I_have_this_card(cards_in_hand, 
                number_of_cards_in_hand, 40) == YES) {
                card[index_for_card] = 40;
                index_for_card++;
            }
        }
    }
    // PLAY THE SELECTED CARD 
    printf("%d\n", card[START]);

}


// ADD A COMMENT HERE EXPLAINING YOUR OVERALL TESTING STRATEGY
/* Principle:
   1. Does the function work. 
      Try a normal value of the function, and test it's expected output. 
      If it has multiple possible outputs, try checking one of each.
   2. Does the function work on edge cases. 
      If the function has edges (for instance, it works between 0 
      and the length of an array), test both those limits.
   3. Does the function fail gracefully. 
      If the function is expecting inputs outside it's "normal range", 
      test that it does the correct behaviour.
   4. Layout for unit tests need to keep the readability.
   5. Andrew Taylor said "Creating files to test input functions, 
      while a good thing to do in general, 
      isn't warranted for this assignment.   
      Similarly you don't need to test printing your player name."
   6. Break up long void function into shorter functions 
      that can have returns, and test that.
   
   Hence, my strategy is: 
   1) For the 3 "big" void functions, create 3 test functions and
      call them in this run_unit_tests function is too coplicated.
      So I will break up them into shorter functions that can have 
      returns, and test that. 
   2) Inside each test functions, create files to test.
   3) For every functions I write, create a test function.
   4) Call those functions from this run_unit_tests function.
   5) In each test function, test edge cases and other various cases.*/
void run_unit_tests(void) {
    test_Do_I_have_this_card();
    test_units_digit_of();
    test_tens_digit_of();
    test_Do_I_have_same_tens_digit_cards();
    test_sum_of_units_digit_of_same_tens_digit();
    test_smallest_same_tens_digit();
    test_second_smallest_same_tens_digit();
    test_smallest_same_tens_digit();
    test_how_many_same_tens_digit();
    test_sum_of_units_digit_of_same_tens_digit();

}

// EXTRA FUNCTIONS
// Give an array and its size, scanf contents into the array.
void read_cards(int how_many_cards, int *cards) {
    int cards_index = START;
    while (cards_index < how_many_cards) {
        scanf("%d", &cards[cards_index]);
        cards_index++;
    }

}

/* Give an integer, an array and its size.
   If this integer is in the array, return 1;
   if it is not in the array, return 0.*/
int Do_I_have_this_card(int *cards_in_hand, 
int number_of_cards_in_hand, int target_number) {
    int numbers_in_array = NO;
    int index_for_array = START;
    while (index_for_array < number_of_cards_in_hand) {
        if (cards_in_hand[index_for_array] == target_number) {
            numbers_in_array = YES;
        }
        index_for_array++;
    }
    
    return numbers_in_array;
}

// Return the units digit of the input
int units_digit_of(int target_number) {
    int digit1 = target_number % 10;
    
    return digit1;
}

// Return the tens digit of the input
int tens_digit_of(int target_number) {
    int digit2 = (target_number - target_number % 10) / 10;
    
    return digit2;
}

/* Give a number, an array and its size.
   If I have number(s) in the array 
   which has same tens digit of the input number,
   return 1;
   if I don't have,
   return 0.*/
int Do_I_have_same_tens_digit_cards(int *cards_in_hand, 
int number_of_cards_in_hand, int target_number) {
    int answer = NO;
    int digit2_of_target_number = tens_digit_of(target_number);
    int digit2_of_target_cards_in_hand[N_CARDS];
    int index1 = START;
    while (index1 < number_of_cards_in_hand) {
        digit2_of_target_cards_in_hand[index1] = 
        tens_digit_of(cards_in_hand[index1]);
        index1++;
    }
    int index2 = START;
    while (index2 < number_of_cards_in_hand) {
        if (digit2_of_target_cards_in_hand[index2] == 
        digit2_of_target_number) {
            answer = YES;
        }
        index2++;
    }
    
    return answer;
}

/* Input an array , its size and a target number.
   Sum the numbers which have the same tens digit
   of the target number*/ 
int sum_of_units_digit_of_same_tens_digit(int *cards_in_hand, 
int number_of_cards_in_hand, int target_number) {
    int sum = START;
    int digit2_of_target_number = tens_digit_of(target_number);
    int digit2_of_target_cards_in_hand[N_CARDS];
    int index1 = START;
    while (index1 < number_of_cards_in_hand) {
        digit2_of_target_cards_in_hand[index1] = 
        tens_digit_of(cards_in_hand[index1]);
        index1++;
    }
    int index2 = START;
    while (index2 < number_of_cards_in_hand) {
        if (digit2_of_target_cards_in_hand[index2] == 
            digit2_of_target_number) {
            sum = sum + cards_in_hand[index2] - 
            10 * digit2_of_target_number;
        }
        index2++;
    }
    
    return sum;
}

/* Give an array and its size, a target
  return the smallest number which has 
  same digit in the array*/    
int smallest_same_tens_digit(int *array, int size, int target) {
    int array1[N_CARDS_INITIAL_HAND];
    int size1 = START;
    int index1 = START;
    while (index1 < size) {
        if (tens_digit_of(target) == tens_digit_of(array[index1])) {
            array1[size1] = array[index1];
            size1++;
        }
        index1++;
    }
    int small = array1[START];
    int index2 = START;
    while (index2 < size1) {
        if (small > array1[index2]) {
            small = array1[index2];
        }
        index2++;
    }
    
    return small;
}

/* Give an array and its size, a target
   return the largest number which has 
   same digit in the array*/
int largest_same_tens_digit(int *array, int size, int target) {
    int array1[N_CARDS_INITIAL_HAND];
    int size1 = START;
    int index1 = START;
    while (index1 < size) {
        if (tens_digit_of(target) == tens_digit_of(array[index1])) {
            array1[size1] = array[index1];
            size1++;
        }
        index1++;
    }
    int large = array1[START];
    int index2 = START;
    while (index2 < size1) {
        if (large < array1[index2]) {
            large = array1[index2];
        }
        index2++;
    }
    
    return large;
}
/* Give an array and its size, and a target,
   return the second smallest number which 
   has the same digit in the array*/
int second_smallest_same_tens_digit(int *array, int size, int target) {  
    int same_tens_array[N_CARDS_INITIAL_HAND];
    int len = START;
    int index1 = START;
    while (index1 < size) {
        if (tens_digit_of(target) == tens_digit_of(array[index1])) {
            same_tens_array[len] = array[index1];
            len++;
        }
        index1++;
    }
    int index2, min = same_tens_array[START], 
        second = same_tens_array[START + 1];  
    if (min > second) {  
        min = same_tens_array[START + 1];  
        second = same_tens_array[START];  
    }  
    for (index2 = 2; index2 < len; ++index2) {  
        if (same_tens_array[index2] < min) {  
            second = min;  
            min = same_tens_array[index2];  
        } else if (same_tens_array[index2] < second) {  
            second = same_tens_array[index2];  
        }  
    }  
    
    return second;  
}

/* Give an array and its size, and a target.
   Return the number of same tens digit integer
   in the array.*/
int how_many_same_tens_digit(int *array, int size, int target) {
    int result = START;
    int index = START;
    while (index < size) {
        if (tens_digit_of(target) == tens_digit_of(array[index])) {
            result++;
        }
        index++;
    }

    return result;
}

/* This function will return an "appropriate" card.
   Which is the largest legal card which can avoid winning.
   If I don't have a card like this, it is the largest legal
   card in hand to avoid wasting small cards.*/
int appropriate_play(int *cards_in_hand, int number_of_cards_in_hand, 
                     int *cards_played_in_round, 
                     int number_of_cards_played_in_round) {
    int appropriate;                     
    int same_tens_arr[N_CARDS_INITIAL_HAND];
    int index_for_arr = START;
    int index1 = START;  
    while (index1 < number_of_cards_in_hand) {
        if (tens_digit_of(cards_played_in_round[START]) == 
            tens_digit_of(cards_in_hand[index1])) {
            same_tens_arr[index_for_arr] = cards_in_hand[index1];
            index_for_arr++;
        }
        index1++;
    }        
    int same_tens_played_in_round[N_CARDS_INITIAL_HAND];
    int number_of_same_tens_played_in_round = START;
    int index0 = START;       
    while (index0 < number_of_cards_played_in_round) {
        if (tens_digit_of(cards_played_in_round[START]) == 
            tens_digit_of(cards_played_in_round[index0])) {
            same_tens_played_in_round
            [number_of_same_tens_played_in_round] = 
            cards_played_in_round[index0];
            number_of_same_tens_played_in_round++;
        }
        index0++;
    }
    // Rearranged in descending order 
    int bridge;
    int i, j;
    for (i = START; i < index_for_arr; ++i) {
        for (j = i + 1; j < index_for_arr; ++j) {
            if (same_tens_arr[i] < same_tens_arr[j]) {
                bridge = same_tens_arr[i];
                same_tens_arr[i] = same_tens_arr[j];
                same_tens_arr[j] = bridge;
            }
        }
    }             
    int result = NO;
    int index2 = START;
    int index3 = START;
    while (index2 < index_for_arr) {    
        index3 = START;
        while (index3 < number_of_same_tens_played_in_round) {
            if (same_tens_arr[index2] < 
                same_tens_played_in_round[index3]) {
                result = YES;
            }          
            index3++;
        }
        if (result == YES) {
            appropriate = same_tens_arr[index2];
            break;
        }
        index2++;
    }
    if (result == NO) {
        if (number_of_cards_played_in_round >= 3) {
            appropriate = largest_same_tens_digit(cards_in_hand, 
            number_of_cards_in_hand, cards_played_in_round[START]);
        } else {
            appropriate = smallest_same_tens_digit(cards_in_hand, 
            number_of_cards_in_hand, cards_played_in_round[START]);
        }
    }
    
    return appropriate;
}

void test_how_many_same_tens_digit(void) {
    int target1 = 10;
    int target2 = 23;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_same_tens_digit_cards
           (array1, size1, target1) == NO);
    assert(Do_I_have_same_tens_digit_cards
           (array2, size2, target2) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array3, size3, target3) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array4, size4, target4) == NO);
    
}

void test_Do_I_have_this_card(void) {
    int target1 = 10;
    int target2 = 22;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_this_card(array1, size1, target1) == NO);
    assert(Do_I_have_this_card(array2, size2, target2) == YES);
    assert(Do_I_have_this_card(array3, size3, target3) == YES);
    assert(Do_I_have_this_card(array4, size4, target4) == NO);

}

void test_units_digit_of(void) {
    assert(units_digit_of(22) == 2);
    assert(units_digit_of(23) == 3);
    assert(units_digit_of(32) == 2);
    assert(units_digit_of(99) == 9);
    
}

void test_smallest_same_tens_digit(void) {
    int target1 = 10;
    int target2 = 23;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_same_tens_digit_cards
           (array1, size1, target1) == NO);
    assert(Do_I_have_same_tens_digit_cards
           (array2, size2, target2) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array3, size3, target3) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array4, size4, target4) == NO);
    
}

void test_second_smallest_same_tens_digit(void) {
    int target1 = 10;
    int target2 = 23;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_same_tens_digit_cards
           (array1, size1, target1) == NO);
    assert(Do_I_have_same_tens_digit_cards
           (array2, size2, target2) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array3, size3, target3) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array4, size4, target4) == NO);

}

void test_tens_digit_of(void) {
    assert(tens_digit_of(22) == 2);
    assert(tens_digit_of(23) == 2);
    assert(tens_digit_of(32) == 3);
    assert(tens_digit_of(99) == 9);
    
}

void test_Do_I_have_same_tens_digit_cards(void) {
    int target1 = 10;
    int target2 = 23;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_same_tens_digit_cards
           (array1, size1, target1) == NO);
    assert(Do_I_have_same_tens_digit_cards
           (array2, size2, target2) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array3, size3, target3) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array4, size4, target4) == NO);

}

void test_sum_of_units_digit_of_same_tens_digit(void) {
    int target1 = 10;
    int target2 = 23;
    int target3 = 35;
    int target4 = 47;
    int size1 = 3;
    int size2 = 5;
    int size3 = 1;
    int size4 = 0;
    int array1[3] = {23, 24, 33};
    int array2[5] = {22, 24, 33, 42, 47};
    int array3[1] = {35};
    int array4[10] = {0};
    assert(Do_I_have_same_tens_digit_cards
           (array1, size1, target1) == NO);
    assert(Do_I_have_same_tens_digit_cards
           (array2, size2, target2) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array3, size3, target3) == YES);
    assert(Do_I_have_same_tens_digit_cards
           (array4, size4, target4) == NO);

}




