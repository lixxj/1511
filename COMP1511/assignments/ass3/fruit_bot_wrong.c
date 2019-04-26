// COMP1511 18s1, Assignment 3: Fruit Bot
//
// Written by Xingjian, Li(z5190719) on 17/05/2018

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fruit_bot.h"

struct trade {
    char                *fruit;
    struct location     *buy_loc;
    struct location     *sell_loc;
    int                 profit;
    int                 amount;
};

struct charge {
    int                 distance;
    struct location     *elec_loc;
};

// #defines

#define TRUE                  1
#define FALSE                 0
#define ONE                   1
#define ZERO                  0
#define SAME                  0
#define CONSTANT1             3

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void);

// PROTOTYPES FUNCTIONS

int bot_count(struct bot *b);
void single_mode(struct bot *b);
void multi_mode(struct bot *b);
int total_demand(struct bot *me, char *fruit);
int can_buy_more_here(struct bot *me);
int can_sell_here(struct bot *me);
int can_charge_here(struct bot *me);
int min_distance(struct location *start, struct location *target);
int getprofit(int trade_amount, struct location *buy_loc, struct location *sell_loc);
int have_profit(struct location *buy_loc, struct location *sell_loc);
int smaller(int value1, int value2);
struct trade best_trade(struct bot *b);

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

// count the number of players
int bot_count(struct bot *b) {
    int bots = ZERO;
    struct location *curr_loc = b->location;
    // Test if no location in the world, return 1, error
    if (curr_loc == NULL) {
        return 1;
    }
    struct bot_list *curr_bot = curr_loc->bots;
    while (curr_bot != NULL) {
        bots++;
        curr_bot = curr_bot->next;
    }                                      
    curr_loc = curr_loc->east;
    while (curr_loc != b->location) {
        curr_bot = curr_loc->bots;
        while (curr_bot != NULL) {
            bots++;
            curr_bot = curr_bot->next;
        }
        curr_loc = curr_loc->east;
    } 
                                             
    return bots;
}

// single player mode
void single_mode(struct bot *b) {
    struct bot *me = b;
    struct location *my_loc = me->location;
    // have fruits
    if (me->fruit_kg > ZERO) {
        // can sell here
        if (can_sell_here(me) == TRUE) {
            printf("Sell %d\n", me->fruit_kg);
        }
        // can't sell here
        if (can_sell_here(me) == FALSE) {
            // can charge here
            if (can_charge_here(me) == TRUE) {
                printf("Buy %d\n", me->battery_capacity);
            }
            // can't charge here
            if (can_charge_here(me) == FALSE) {
                // don't need to charge
                if () {
                    // go to the best place to sell
                    
                }
                // need to charge 
                if () {
                
                }
            }
        }
    
    }
    // don't have fruits and turns allowed
    if (me->fruit_kg == ZERO && ) {
        // get the best trade information
        struct trade best = best_trade(b);
        int displacement = min_distance(me->location, best.buy_loc);
        if (best.profit >= CONSTANT1 * me->battery_capacity) {
            // if at right place
            if (me->location == best.buy_loc) {
                printf("Buy %d\n", best.amount);
            }
            // if not at right place
            if (me->location != best.buy_loc) {
                // don't need to charge
                if (need_charge(me, best.buy_loc) == FALSE) {
                    printf("Move %d\n", displacement);
                }
                // need to charge
                if (need_charge(me, best.buy_loc) == TRUE) {
                    // if at elec-station charge to full
                    if () {
                    
                    }
                    // if not at elec-station 
                    if () {
                    
                    }
                }
            }
        } else {
            printf("Move 0\n");
        }
    } else {
        printf("Move 0\n");
    }

}

// multi-players mode
void multi_mode(struct bot *b) {
    int players = bot_count(b);
}

// check battery level and decide whether need to charge
int need_charge(struct bot *me, struct location *destination) {
    if () {
        return TRUE;
    } else {
        return FALSE;
    }
}

// find the best place to charge
struct charge best_charge(struct location *myloc, struct location *destination) {
    /* struct charge {
       int                 distance;
       struct location     *elec_loc;
       }; */
    struct charge best;
    struct location *curr_loc = myloc;
    // first consider best is the nearest one
    best = charge nearest_elec(myloc);
    // A charge station between me and destination is better
    while (curr_loc != destination) {
        // go east to the destination
        if (min_distance(curr_loc, destination) >= ZERO) {
            if () {
            
            } 
            curr_loc = curr_loc->east;
        }
        // go west to the destination
        if (min_distance(curr_loc, destination) < ZERO) {
            if () {
            
            }
            curr_loc = curr_loc->west;
        }
    }
    
    
    
    return best;
}

// return distance to nearest electricity and that location
// if nearest electricity is west return negative int
// if nearest electricity is current location return 0
struct charge nearest_elec(struct location *start) {
    struct charge nearest;
    int distW = ZERO;
    int distE = ZERO;
    struct location *currW = start;
    struct location *currE = start;
    if (currW->fruit != NULL && strcmp("Electricity", currW->fruit) == 
        ZERO || strcmp("Electricity", currE->fruit) == ZERO) {
        nearest.distance = ZERO;
        nearest.elec_loc = start;
        
        return nearest;
    }
    currW = currW->west;
    currE = currE->east;
    while (currW != start) {
        distW++;
        if (currW->fruit != NULL 
            && strcmp("Electricity", currW->fruit) == SAME) {
            break;
        }
        currW = currW->west;
    }
    while (currE != start) {
        distE++;
        if (currE->fruit != NULL 
            && strcmp("Electricity", currE->fruit) == SAME) {
            break;
        }
        currE = currE->east;
    }
    if (distW <= distE) {
        nearest.distance = -distW;
        nearest.elec.loc = currW;
    } else {
        nearest.distance = distE;
        nearest.elec.loc = currE;
    }
    return nearest;
}

// find the best fruit and places to buy and sell
struct trade best_trade(struct bot *b) {
    /* struct trade has five elements to store best trade informaion
       char                *fruit;
       struct location     *buy_loc;
       struct location     *sell_loc;
       int                 profit; 
       int                 amount; */
    struct trade best;
    strcpy(best.fruit, b->location->fruit);
    best.buy_loc = b->location;
    best.sell_loc = b->location;
    best.profit = ZERO;
    // Location I buy and sell fruits 
    struct location *buy_loc = b->location;
    struct location *sell_loc = b->location;
    
    int trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
    int profit;
    if (have_profit(buy_loc, sell_loc) == TRUE) {
        profit = getprofit(trade_amount, buy_loc, sell_loc);
    } else {
        profit = ZERO;
    }
    if (profit >= best.profit) {
        strcpy(best.fruit, buy_loc->fruit);
        best.buy_loc = buy_loc;
        best.sell_loc = sell_loc;
        best.profit = profit;
        best.amount = trade_amount;
    }
    sell_loc = sell_loc->east;
    while (sell_loc != b->location && sell_loc != NULL) {
        trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
        if (have_profit(buy_loc, sell_loc) == TRUE) {
            profit = getprofit(trade_amount, buy_loc, sell_loc);
        } else {
            profit = ZERO;
        }
        
        if (profit >= best.profit) {
            strcpy(best.fruit, buy_loc->fruit);
            best.buy_loc = buy_loc;
            best.sell_loc = sell_loc;
            best.profit = profit;
            best.amount = trade_amount;
        }
        sell_loc = sell_loc->east;
    }
    buy_loc = buy_loc->east;
    while (buy_loc != b->location && buy_loc != NULL) {
        trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
        if (have_profit(buy_loc, sell_loc) == TRUE) {
            profit = getprofit(trade_amount, buy_loc, sell_loc);
        } else {
            profit = ZERO;
        }
        if (profit >= best.profit) {
            strcpy(best.fruit, buy_loc->fruit);
            best.buy_loc = buy_loc;
            best.sell_loc = sell_loc;
            best.profit = profit;
            best.amount = trade_amount;
        }
        sell_loc = sell_loc->east;
        while (sell_loc != b->location && sell_loc != NULL) {
            trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
            if (have_profit(buy_loc, sell_loc) == TRUE) {
                profit = getprofit(trade_amount, buy_loc, sell_loc);
            } else {
                profit = ZERO;
            }
            if (profit >= best.profit) {
                strcpy(best.fruit, buy_loc->fruit);
                best.buy_loc = buy_loc;
                best.sell_loc = sell_loc;
                best.profit = profit;
                best.amount = trade_amount;
            }
            sell_loc = sell_loc->east;
        }
        buy_loc = buy_loc->east;
    }
    
    return best;
}

// calculate the profit of a trade
int getprofit(int trade_amount, struct location *buy_loc, struct location *sell_loc) {
    int profit = trade_amount * (buy_loc->price + sell_loc->price);
    
    return profit; 
}
   
// check if two locations have same fruits and one buy one sell
int have_profit(struct location *buy_loc, struct location *sell_loc) {
    if (strcmp(buy_loc->fruit, buy_loc->fruit) == SAME 
        && buy_loc->price < ZERO && sell_loc->price > ZERO) {
        return TRUE;
    } else {
        return FALSE;
    }
    
}
// return the smaller value of two integers
int smaller(int value1, int value2) {
    if (value1 <= value2) {
        return value1;
    } else {
        return value2;
    }

}

/*// check if enough turns left to move buy and SELL
// to prevent holding fruits in the end
???? enough_turns_left(struct bot *b) {


    return ;
}*/

// count the minimum distance between two locations
// if go east is closer, distance is positive
// if go west is closer, distance is negative
int min_distance(struct location *start, struct location *target) {
    int dist;
    int distW = ZERO;
    int distE = ZERO;
    struct location *currW = start;
    struct location *currE = start;
    while (currW != target) {
        distW++;
        currW = currW->west;
    }
    while (currE != target) {
        distE++;
        currE = currE->east;
    }
    if (distW <= distE) {
        dist = -distW;
    } else {
        dist = distE;
    }
    
    return dist;
}

// check if I can sell the fruit I have in the current location
// if I can return TRUE, if I can't return FALSE
int can_sell_here(struct bot *me) {
    // location BUYS the fruit I have and still want to buy some 
    struct location *here = me->location;
    if (here->fruit != NULL && strcmp(here->fruit, me->fruit) == SAME 
        && here->quantity > ZERO && here->price > ZERO) {
        return TRUE;
    } else {
        return FALSE;
    }
    
}

// check if I can buy electricity in the current location
// if I can return TRUE, if I can't return FALSE
int can_charge_here(struct bot *me) {
    // location SELLS Electricity and still have some 
    // and battery level is not full
    struct location *here = me->location;
    if (here->fruit != NULL && strcmp(here->fruit, "Electricity") 
        == SAME && here->quantity > ZERO  
        && me->battery_level < me->battery_capacity) {
        return TRUE;
    } else {
        return FALSE;
    }

}

// check if I can buy more fruits(is carrying) in the current location
// if I can return TRUE, if I can't return FALSE
int can_buy_more_here(struct bot *me) {
    return 0;
}

// calculate total demand of certain fruits in the world
int total_demand(struct bot *me, char *fruit) {
    int demand = ZERO;
    struct location *here = me->location;
    if (strcmp(here->fruit, fruit) == SAME && here->price > ZERO) {
        demand = demand + here->quantity;
    }
    here = here->east;
    while (here != me->location && here != NULL) {
        if (strcmp(here->fruit, fruit) == SAME && here->price > ZERO) {
            demand = demand + here->quantity;
        }
    }
    
    return demand;
}


