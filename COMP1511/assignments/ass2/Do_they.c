/* Input the previous cards and its size, cards in hand and its size,
   and a target card.
   Determine which cards are in other players' hand,
   then if they have same tens digit cards and 
   one of them are larger than the target card,
   return 1;
   otherwise, return 0;*/
int do_they_have_a_same_tens_larger_one(int candidate, int *previous_cards, int number_of_previous_cards, int *cards_in_hand, int number_of_cards_in_hand) {
    int result = NO;
    int remain[40 - number_of_previous_cards];
    int i1 = 10;
    int i2 = START;
    while (i1 < 50) {
        if (Do_I_have_this_card(previous_cards, number_of_previous_cards, candidate) == NO && Do_I_have_this_card(cards_in_hand, number_of_cards_in_hand, candidate) == NO) {
            remain[i2] = i1;
            i2++;
        }
        i1++;
    }
    int index = START;
    while (index < i2) {
        if (tens_digit_of(candidate) == tens_digit_of(remain[index]) && remain[index] > candidate) {
            result = YES;
        }
        index++;
    }

    return result;
}
