// Written by XJ LI

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "fruit_bot.h"

void print_player_name(void);
void print_move(struct bot *b);

int main(int argc, char *argv[]) {
    struct bot *me = fruit_bot_input(stdin);
    if (me == NULL) {
        print_player_name();
    } else {
        print_move(me);
    }

    return 0;
}

void print_player_name(void) {
    printf("West McWesty");

}

// print_move - should print a single line indicating
//              the move you bot wishes to make
//
// This line should contain only the word Move, Sell or Buy
// followed by a single integer

void print_move(struct bot *b) {
    struct bot *curr = b;
    // the location sells Electricity, has some kJ left to sell and battery is not full  
    if (strcmp(curr->location->fruit, "Electricity") == 0 && 
        curr->location->quantity > 0 && 
        curr->battery_level < curr->battery_capacity) {
       
        printf("Buy %d\n", (curr->battery_capacity - curr->battery_level));
        
    } else if (strcmp(curr->location->fruit, "Apples") == 0 && curr->location->quantity > 0) {
        // has no fruit on board, the location sells Apples and it has some left to sell
        // buy as many kg of apples as bot can carry
        if (curr->fruit_kg == 0 && curr->location->price < 0) {
            
            printf("Buy %d\n", curr->maximum_fruit_kg);
        } else if (curr->fruit_kg > 0 && curr->location->price > 0) {
            // has apples on board, location buys apples and still willing to buy some
            // sell all apples
            printf("Sell %d\n", curr->fruit_kg);
        } else {
            // move west as many locations as permitted
            printf("Move -%d\n", curr->maximum_move);
        }
    } else {
        // move west as many locations as permitted
        printf("Move -%d\n", curr->maximum_move);
    }
}
