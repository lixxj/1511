// COMP1511 18s1, Assignment 3: Fruit Bot
//
// Written by 

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fruit_bot.h"

struct Recharge_values {
    struct location     *buy_loc;
    int                 *qty;
    int                 *price;
    int                 can_recharge_if_here
    int 
    int 
};

// #defines

#define TRUE                  1
#define FALSE                 0
#define ONE                   1
#define ZERO                  0
#define SAME                  0

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void);

// PROTOTYPES

int bot_count(struct bot *b);
void single_mode(struct bot *b);
void multi_mode(struct bot *b);


int main(int argc, char *argv[]) {

    if (argc > 2) {
        // supply any command-line argument to run unit tests
        run_unit_tests();
        return 0;
    }

    struct bot *me = fruit_bot_input(stdin);
    if (me == NULL) {
        print_player_name();
    } else {
        print_move(me);
    }

    return 0;
}

// PLAYER NAME
void print_player_name(void) {
    printf("404 not found\n");

}

// print_move - should print a single line indicating
//              the move your bot wishes to make
//
// This line should contain only the word Move, Sell or Buy
// followed by a single integer, ie: "printf("Move 1\n");"
void print_move(struct bot *b) {
    // get the number of players
    int players = bot_count(b);
    // single player mode
    if (players == ONE) {
        single_mode(b);
    }
    // multi-players mode
    if (players > ONE) {
        multi_mode(b);
    }

}

// OVERALL TESTING STRATEGY
/* Principle:
   1. Does the function work. 
      Try a normal value of the function, and test it's expected output. 
      If it has multiple possible outputs, try checking one of each.
   2. Does the function work on EDGE cases. 
      If the function has edges (for instance, it works between 0 
      and the length of an array), test both those limits.
   3. Does the function fail gracefully. 
      If the function is expecting inputs outside it's "normal range", 
      test that it does the correct behaviour.
   4. Layout for unit tests need to keep the readability.
      Create seperate test functions and call them in the 
      run_unit_tests function.*/
   
void run_unit_tests(void) {
    
    
}

// FUNCTIONS

void single_mode(struct bot *b) {
    // no fruit in hand
    if (b->fruit_kg > 0) {
        buy_mode(b);
    }
    // have fruits
    if () {
    
    }



}

void multi_mode() {







}
