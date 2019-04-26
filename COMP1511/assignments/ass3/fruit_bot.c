// COMP1511 18s1, Assignment 3, Fruit Bot
//
// Written by Xingjian Li, z5190719, May 2018

#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "fruit_bot.h"

// #defines

#define TRUE                  1
#define FALSE                 0
#define ONE                   1
#define ZERO                  0
#define SAME                  0
#define TWO                   2
#define THREE                 3
#define SIX                   6

struct trade {
    struct location     *buy_loc;
    struct location     *sell_loc;
    int                 profit;
    int                 amount;
};

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void);

// PROTOTYPES
int bot_count(struct bot *b);
void single_mode(struct bot *b);
void multi_mode(struct bot *b);
int nearest_elec(struct location *start);
int best_sell(struct bot *b);
struct trade best_trade_single(struct bot *b);
struct trade best_trade_multi(struct bot *b);
int world_size(struct bot *b);
int getprofit(int trade_amount, struct location *buy_loc, 
    struct location *sell_loc);
int have_profit(struct location *buy_loc, struct location *sell_loc);
int smaller(int value1, int value2);
int can_sell_here(struct bot *me);
int can_charge_here(struct bot *me);
void stay(void);
void test_bot_count(void);
void test_nearest_elec(void);
void test_min_distance(void);
void test_smaller(void);
int min_distance(struct location *start, struct location *target);
int need_charge(struct bot *b, struct location *destination);
void test_can_sell_here(void);
void test_can_charge_here(void);
void test_world_size(void);

// YOU SHOULD NOT NEED TO CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    if (argc > 1) {
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

void print_player_name(void) {
    // PLAYER NAME
    printf("organ15");

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
      Try a normal value of the function, and test it's expected output 
      If it has multiple possible outputs, try checking one of each.
   2. Does the function work on EDGE cases. 
      If the function has edges, test both those limits.
   3. Does the function fail gracefully. 
      If the function is expecting inputs outside it's "normal range", 
      test that it does the correct behaviour.
   4. Layout for unit tests need to keep the readability.
      Create seperate test functions and call them in the 
      run_unit_tests function. 
   
   Procedure:
   
   1. The unit tests for functions take in "struct bot" or 
   "struct location" will be difficult to test but it is possible.
   Create files containing a test world(which we know the results),
   input it to the functions we need to test, and check the result.
   
   2. For other functions take in normal variales, test normal cases 
   the test the edge cases particularly, check do they have any error.
   
   3. Make each test group for a function a seperate function to keep
   redability. */
   
void run_unit_tests(void) {
    test_bot_count();
    test_nearest_elec();
    test_min_distance();
    test_smaller();
    test_can_sell_here();
    test_can_charge_here();
    test_world_size();
    
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
    
    // have fruits
    if (b->fruit_kg > ZERO) {
        
        if (can_sell_here(b) == TRUE) {
            printf("Sell %d\n", b->fruit_kg);
        } else if (can_sell_here(b) == FALSE) {
            // go to the best place to sell
            printf("Move %d\n", best_sell(b));
        } else {
            stay();
        }
    }
    
    // get the best trade information
    struct trade best = best_trade_single(b);
    int displacement1 = min_distance(b->location, best.buy_loc);
    int displacement2 = min_distance(best.buy_loc, best.sell_loc);
    // don't have fruits and turns allowed
    if (b->fruit_kg == ZERO) {
        if (b->turns_left > 
            (displacement1 + displacement2) / b->maximum_move + THREE) {
            
            // if at right place
            if (b->location == best.buy_loc) {
                printf("Buy %d\n", best.amount);
            }
            // if not at right place
            if (b->location != best.buy_loc) {
                // don't need to charge
                if (need_charge(b, best.buy_loc) == FALSE) {
                    printf("Move %d\n", displacement1);
                }
                // need to charge
                if (need_charge(b, best.buy_loc) == TRUE) {
                    // if at elec-station charge to full
                    if (can_charge_here(b) == TRUE 
                        && b->turns_left > SIX) {
                        
                        printf("Buy %d\n", b->battery_capacity);
                    } else if (can_charge_here(b) == TRUE) {
                        
                        printf("Move 0");
                    }
                    // if not at elec-station move to nearest one 
                    if (can_charge_here(b) == FALSE) {
                        printf("Move %d\n", nearest_elec(b->location));
                    }
                }
            }
        } else {
            stay();
        }
    }

}

// find the best fruit and places to buy and sell in single mode
struct trade best_trade_single(struct bot *b) {
    /* struct trade has five elements to store best trade informaion
       struct location     *buy_loc;
       struct location     *sell_loc;
       int                 profit; 
       int                 amount; */
    struct trade best;
    best.buy_loc = b->location;
    best.sell_loc = b->location;
    best.profit = ZERO;
    best.amount = ZERO;
    // Location I buy and sell fruits 
    struct location *buy_loc = b->location;
    struct location *sell_loc = b->location;
    int mark1 = ZERO;
    int mark2 = ZERO;
    int profit = ZERO;
    int trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
    while (buy_loc != b->location || mark1 == ZERO) {
        mark1 = ONE;
        mark2 = ZERO;
        sell_loc = b->location;
        while (sell_loc != b->location || mark2 == ZERO) {
            
            trade_amount = smaller(buy_loc->quantity, 
            sell_loc->quantity);
            profit = ZERO;
            mark2 = ONE;
            if (have_profit(buy_loc, sell_loc) == TRUE) {
                profit = getprofit(trade_amount, buy_loc, sell_loc);
            } 
            if (profit > best.profit) {
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

// multi-players mode
void multi_mode(struct bot *b) {
    // have fruits
    if (b->fruit_kg > ZERO) {
        
        if (can_sell_here(b) == TRUE) {
            printf("Sell %d\n", b->fruit_kg);
        } else if (can_sell_here(b) == FALSE) {
            // go to the best place to sell
            printf("Move %d\n", best_sell(b));
        } else {
            stay();
        }
    }
    
    // get the best trade information
    struct trade best = best_trade_single(b);
    int displacement1 = min_distance(b->location, best.buy_loc);
    int displacement2 = min_distance(best.buy_loc, best.sell_loc);
    // don't have fruits and turns allowed
    if (b->fruit_kg == ZERO) {
        if (b->turns_left > 
            (displacement1 + displacement2) / b->maximum_move + THREE) {
            
            // if at right place
            if (b->location == best.buy_loc) {
                printf("Buy %d\n", best.amount);
            }
            // if not at right place
            if (b->location != best.buy_loc) {
                // don't need to charge
                if (need_charge(b, best.buy_loc) == FALSE) {
                    printf("Move %d\n", displacement1);
                }
                // need to charge
                if (need_charge(b, best.buy_loc) == TRUE) {
                    // if at elec-station charge to full
                    if (can_charge_here(b) == TRUE 
                        && b->turns_left > SIX) {
                        
                        printf("Buy %d\n", b->battery_capacity);
                    } else if (can_charge_here(b) == TRUE) {
                        
                        printf("Move 0");
                    }
                    // if not at elec-station move to nearest one 
                    if (can_charge_here(b) == FALSE) {
                        printf("Move %d\n", nearest_elec(b->location));
                    }
                }
            }
        } else {
            stay();
        }
    }

}

// check does the bot need to recharge
int need_charge(struct bot *b, struct location *destination) {
    int result;
    if (b->battery_level < b->battery_capacity && b->battery_level > 
        (min_distance(b->location, destination) + 
        nearest_elec(destination))) {
        
        result = TRUE;
    } else {
        result = FALSE;
    }

    return result;
}

// return distance to nearest electricity and that location
// if nearest electricity is west return negative int
// if nearest electricity is current location return 0
int nearest_elec(struct location *start) {
    int nearest;
    int distW = ZERO;
    int distE = ZERO;
    struct location *currW = start;
    struct location *currE = start;
    if (currW->fruit != NULL && (strcmp("Electricity", currW->fruit) == 
        ZERO || strcmp("Electricity", currE->fruit) == ZERO)) {
        nearest = ZERO;
        
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
        nearest = -distW;
    } else {
        nearest = distE;
    }
    return nearest;
}

// return the distance from current to best sell place
int best_sell(struct bot *b) {
    int size = world_size(b);
    int i = ONE;
    struct location *loc = b->location->east;
    int best = i;
    int max_profit = smaller(b->fruit_kg, loc->quantity) * loc->price;
    while (loc != b->location) {
        if (smaller(b->fruit_kg, loc->quantity) * 
            loc->price > max_profit) {
            
            max_profit = smaller(b->fruit_kg, 
            loc->quantity) * loc->price;
            best = i;
        }
        loc = loc->east;
        i++;
    }
    
    return best;
}

// return the world size
int world_size(struct bot *b) {
    int size = TWO;
    struct location *curr_loc = b->location->east;
    while (curr_loc != b->location) {
        size++;
        curr_loc = curr_loc->east;
    }
    return size;
}

// find the best fruit and places to buy and sell in multi mode
struct trade best_trade_multi(struct bot *b) {
    /* struct trade has five elements to store best trade informaion
       struct location     *buy_loc;
       struct location     *sell_loc;
       int                 profit; 
       int                 amount; */
    struct trade best;
    best.buy_loc = b->location;
    best.sell_loc = b->location;
    best.profit = ZERO;
    // Location I buy and sell fruits 
    struct location *buy_loc = b->location->east;
    struct location *sell_loc = b->location->east;
    int profit = ZERO;
    int trade_amount = smaller(buy_loc->quantity, sell_loc->quantity);
    while (buy_loc != b->location) {
        while (sell_loc != b->location) {
            if (have_profit(buy_loc, sell_loc) == TRUE) {
                profit = getprofit(trade_amount, buy_loc, sell_loc);
            } else {
                profit = ZERO;
            }
            if (profit > best.profit) {
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
int getprofit(int trade_amount, struct location *buy_loc, 
              struct location *sell_loc) {
    
    int profit = trade_amount * (buy_loc->price + sell_loc->price);
    
    return profit; 
}
   
// check if two locations have same fruits and one buy one sell
int have_profit(struct location *buy_loc, struct location *sell_loc) {
    if (strcmp(buy_loc->fruit, sell_loc->fruit) == SAME 
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

// do nothing
void stay(void) {
    printf("Move 0\n");

}

// UNIT TEST FUNCTIONS

void test_bot_count(void) {
    /* strategy: 
       create sample worlds contain different numbers of players
       assert all of the worlds to check is there any bugs */
    
}

void test_smaller(void) {
    // this is a function takes in integers hence can actually do it
    int test1[2] = {0, 0};
    int test2[2] = {5, 0};
    int test3[2] = {5, 5};
    assert(smaller(test1[0], test1[1]) == 0);
    assert(smaller(test2[0], test2[1]) == 0);
    assert(smaller(test3[0], test3[1]) == 5);

}

void test_nearest_elec(void) {
    /* strategy:
       create sample worlds and sample bots have different locations
       to charge, assert them to check bugs */
       
}
    
void test_min_distance(void) {
    /* strategy:
       create samples worlds, given two randoms lications in the world
       assert the actual distance and return value, to find bugs */

}

void test_can_sell_here(void) {
    /* strategy:
       create sample worlds and sample bots have different locations
       to charge, assert them to check bugs */

}

void test_can_charge_here(void) {
    /* strategy:
       create sample worlds and sample bots have different locations
       to charge, assert them to check bugs */

}

void test_world_size(void) {
    /* strategy:
       create sample worlds have konwn sizes, 
       assert them to check bugs */

}

