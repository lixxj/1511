// COMP1511 18s1, Assignment 3, Fruit Bot
//
// Written by Xingjian Li, z5190719, May 2018

#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "fruit_bot.h"

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void); 

// #defines here 

#define INITIAL_VALUE       -1 
#define MOVE                0 
#define BUY                 1 
#define SELL                2 
#define TRUE                1 
#define FALSE               0
#define ZERO                0
#define SAME                0
#define ONE                 1
#define TWO                 2

// function propotypes here

int bot_count(struct location *location); 
int max_element(int length, int array[length]);
void singleplayer(struct bot *player); 
void sanitize_array(int length, int array[length]); 
int asset_sellers(struct bot *player, char* asset_name, 
                  int world_size, int locations[world_size]);
int asset_buyers(struct bot *player, char* asset_name, 
                 int world_size, int locations[world_size]);
int net_income(struct bot *player, struct location *curr_location, 
               int world_size, int locations[world_size][world_size]); 
int net_assets(struct bot *player, struct location *curr_location, 
               int world_size, int locations[world_size]); 
int move_cost(int fuel, struct location *location_at, 
              struct location *location_to);
int can_recharge(struct bot *player, struct location *location); 
int path(struct location *location_a, struct location  *location_b);
int count_locations(struct location *location); 
int count_fruit_types(struct location *location); 
int price_difference(struct location *sale, struct location *purchase);
int nearest_recharge(struct location *location_at, int directions[TWO]);
void index_to_location_name(struct location *curr_location,  
     int index, int world_size, char name[MAX_NAME_CHARS]);
void move_to(struct bot *player, int world_size, int location_index);
void sellout(struct bot *player); 
void buyout(struct bot *player);
void recharge(struct bot *player);
void move_to_sell(struct bot *player, int fuel_cost, 
     int distance, int world_size, int stock_buyers[world_size]); 
void move_to_buy(struct bot *player);
void thru_recharge(struct bot *player, int world_size, 
                   int location_index); 
int smallest_ring_number(int world_size, int number);
void ring_adjust_array(int length, int array[length], 
                       int adjust_factor);
int player_can_buy(struct bot *player, struct location *location);
int player_can_sell(struct bot *player, struct location *location);
int player_can_recharge(struct bot *player, struct location *location);
int quantity_to_buy(struct bot *player, struct location *location);
int should_recharge(struct bot *player, int fuel_cost);
int lowest_fuel_price(struct bot *player);
void sell_mode(struct bot *player);
void buy_mode(struct bot *player); 
void recharge_mode(struct bot *player);

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
    
    printf("404 NOT FOUND");

}
void print_move(struct bot *b) {

    int players = INITIAL_VALUE; 
    players = bot_count(b->location); 

    if(players == ONE){ 
        singleplayer(b); 
    } else if(players > ONE) { 
        singleplayer(b);
         
    }
}

// unit test strategy and functions
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
      run_unit_tests function. */
// 
void run_unit_tests(void) {
    // PUT YOUR UNIT TESTS HERE
    // This is a difficult assignment to write unit tests for,
    // but make sure you describe your testing strategy above.
}

// functions

int bot_count(struct location *curr_location) { 

    int players = ZERO; 

    // Count the number of bots in the current location.
    if(curr_location->bots != NULL) { 
        players++; 
    }
    for(struct bot_list *curr_list = curr_location->bots->next;
        curr_list != curr_location->bots->next; 
        curr_list = curr_location->bots) { 
        
        if(curr_list != NULL) { 
            players++; 
        }
    }
    // Count the number of bots in other locations. 
    for(struct location *new_location = curr_location->east; 
    new_location != curr_location; new_location = new_location->east) { 
        
        if(new_location->bots == NULL) { 
            players += ZERO; 
        } else { 
            if(new_location->bots->bot != NULL) { 
                players++; 
            }
            for(struct bot_list *new_list = new_location->bots->next; 
            new_list != NULL && new_list != new_location->bots; new_list = new_list->next) { 
                if(new_list != NULL) { 
                    players++; 
                }
            }            
        }
    }

    return players; 
}
void singleplayer(struct bot *player) {

    if(player->fruit_kg != ZERO) { 
        sell_mode(player);
    } else { 
        buy_mode(player);
    }

}
int max_element(int length, int array[length]) { 
    int maximum_element = array[ZERO]; 
    int max_element_index = ZERO; 
    for(int i = 1; i < length; i++) { 
        if(array[i] > maximum_element) { 
            maximum_element = array[i]; 
            max_element_index = i; 
        }
    }

    return max_element_index; 
}
void sanitize_array(int length, int array[length]) { 
    for(int i = ZERO; i < length; i++) { 
        array[i] = -1; 
    }
}
int asset_sellers(struct bot *player, char* asset_name, 
                  int world_size, int locations[world_size]) { 

    int n_sellers = ZERO; 
    struct location *curr_location; 
    curr_location = player->location; 
    // Clean up the array before use. 
    sanitize_array(world_size, locations);
    // Check if the current location sells asset_name
    if(strcmp(asset_name, curr_location->fruit) == SAME 
       && curr_location->price < ZERO) { 
        
        n_sellers++;
        locations[ZERO] = curr_location->quantity; 
    } else { 
        n_sellers++;
    }
    // Count each other location if they sell asset_name
    for(struct location *new_location = curr_location->east; 
    new_location != curr_location; new_location = new_location->east) { 

        if(strcmp(asset_name, new_location->fruit) == SAME 
        && new_location->price < ZERO) { 

            locations[n_sellers] = curr_location->quantity; 
            n_sellers++;

        } else { 
            locations[n_sellers] = ZERO;
        }

    }
    
    return n_sellers; 
}
int asset_buyers(struct bot *player, char* asset_name, 
                 int world_size, int locations[world_size]){

    int n_buyers = ZERO; 
    struct location *curr_location; 
    curr_location = player->location; 

    // Clean up the array before use 
    sanitize_array(world_size, locations);

    // Check if the current location buys certain fruit
    if(strcmp(asset_name, curr_location->fruit) == SAME 
    && curr_location->price > ZERO && curr_location->quantity > ZERO) { 

        n_buyers++;
        locations[ZERO] = abs(curr_location->price); 

    } else { 
        locations[ZERO] = ZERO;
        n_buyers++;
    }
    // Count each other location if they buy certain fruit
    for(struct location *new_location = curr_location->east; 
    new_location != curr_location; new_location = new_location->east) { 

        if(strcmp(asset_name, new_location->fruit) == SAME 
        && player_can_sell(player, new_location)) { 

            locations[n_buyers] = abs(new_location->price); 
            n_buyers++;

        } else { 
            locations[n_buyers] = ZERO;
            n_buyers++;
        }

    }
    
    return n_buyers; 
}
int net_income(struct bot *player, struct location *curr_location, 
               int world_size, int locations[world_size][world_size]) {

    int maximal_income_location = INITIAL_VALUE;
    int maximums[world_size];
    sanitize_array(world_size, maximums);
    int i = ZERO;
    int j = ZERO;
    int buy_price = INITIAL_VALUE; 
    int sell_price = INITIAL_VALUE; 
    int buy_qty = INITIAL_VALUE; 
    int sell_qty = INITIAL_VALUE;

    if(strcmp(curr_location->fruit, "Nothing") != SAME 
    && strcmp(curr_location->fruit, "Electricity") != SAME 
    && curr_location->price < ZERO) { 

        buy_price = abs(curr_location->price); 
        
        if(curr_location->quantity > player->maximum_fruit_kg) {
            buy_qty = player->maximum_fruit_kg - player->fruit_kg;
        } else { 
            buy_qty = curr_location->quantity;
        }

        locations[ZERO][ZERO] = ZERO; 
        j = ONE; 
        
        for(struct location *search = curr_location->east;
            search != curr_location 
            && j < world_size; search = search->east) { 

            sell_qty = ZERO;
            sell_price = ZERO;

            if(strcmp(search->fruit, "Nothing") != SAME 
            && strcmp(search->fruit, "Electricity") != SAME 
            && search->price > ZERO){

                sell_price = search->price; 
                if(search->quantity > buy_qty) { 
                    sell_qty = buy_qty;
                } else if(search->quantity <= buy_qty) { 
                    sell_qty = search->quantity;
                }

                locations[i][j] = (sell_price - buy_price)*sell_qty;
                j++;

            } else { 
                locations[i][j] = ZERO; 
                j++;
            }
        }
    } else { 
        for(int k = ZERO; k < world_size; k++) { 
            locations[ZERO][k] = ZERO;
        }
    }

    i = 1;
    for(struct location *i_search = curr_location->east;
        i_search != curr_location && i < world_size; 
        i_search = i_search->east) { 

        if(strcmp(i_search->fruit, "Nothing") != SAME 
        && strcmp(i_search->fruit, "Electricity") != SAME 
        && i_search->price < ZERO){

            buy_price = abs(i_search->price);
            
            if(i_search->quantity > player->maximum_fruit_kg) {
                buy_qty = player->maximum_fruit_kg;
            } else { 
                buy_qty = i_search->quantity;
            }

            if(strcmp(curr_location->fruit, i_search->fruit) == SAME 
            && curr_location->price > ZERO) { 

                sell_price = curr_location->price; 

                if(curr_location->quantity > buy_qty) { 

                    sell_qty = buy_qty;

                } else { 
                    sell_qty = curr_location->quantity;
                }

                locations[i][ZERO] = (sell_price - buy_price)*sell_qty;
            }            

            j = ONE;
            for(struct location *j_search = curr_location->east; 
                j_search != curr_location && j < world_size; 
                j_search = j_search->east) {

                sell_price = ZERO; 
                sell_qty = ZERO;

                if(i == j){ 
                    locations[i][j] = ZERO;
                    j++;
                } else { 

                    if(strcmp(i_search->fruit, j_search->fruit) == SAME 
                       && j_search->price > SAME) { 

                        sell_price = j_search->price; 

                        if(j_search->quantity > buy_qty) { 

                            sell_qty = buy_qty;

                        } else { 
                            sell_qty = j_search->quantity;
                        }

                        locations[i][j] = (sell_price - 
                        buy_price) * sell_qty;
                        j++;

                    } else { 
                        locations[i][j] = ZERO; 
                        j++;   
                   }

                }
            }
            i++;
        } else { 

            for(int k = ZERO; k < world_size; k++) { 
                locations[i][k] = ZERO;
            }
            i++;
        }
    }

    for(int k = ZERO; k < world_size; k++) { 
        maximums[k] = locations[k][max_element
        (world_size, locations[k])];
    }
    maximal_income_location = maximums[max_element
    (world_size, maximums)];

    return maximal_income_location;
}
int net_assets(struct bot *player, struct location *curr_location, 
               int world_size, int locations[world_size]) { 

    int maximal_asset_location = INITIAL_VALUE;
    int asset_values[world_size][world_size];

    for(int i = ZERO; i < world_size; i++) { 
        sanitize_array(world_size, asset_values[i]);
    }

    net_income(player, curr_location, world_size, asset_values);

    for(int i = ZERO; i < world_size; i++) { 
        locations[i] = asset_values[i][max_element 
        (world_size, asset_values[i])];
        if(locations[i] == INITIAL_VALUE) { 
            locations[i] = ZERO;
        }
    }

    maximal_asset_location = locations[max_element
    (world_size, locations)];

    return maximal_asset_location;
}
int nearest_recharge(struct location *location_at, 
                     int directions[TWO]) {

    int moves_needed = INITIAL_VALUE; 
    int moves_needed_east = INITIAL_VALUE;
    int moves_needed_west = INITIAL_VALUE;
    int moves_taken = INITIAL_VALUE;
    int world_size = count_locations(location_at);

    if(strcmp(location_at->fruit, "Electricity") == SAME 
    && location_at->quantity != ZERO) { 

        moves_needed_east = ZERO; 
        moves_needed_west = ZERO;

    } else { 

        moves_taken = ONE;
        for(struct location *new_location = location_at->east; 
            new_location != location_at; 
            new_location = new_location->east) { 

            if(strcmp(new_location->fruit, "Electricity") == SAME 
            && new_location->quantity != ZERO) { 
                moves_needed_east = moves_taken;
                break;
            } else { 
                moves_taken++;
            }
        }

        moves_taken = ONE;
        for(struct location *new_location = location_at->west; 
            new_location != location_at; 
            new_location = new_location->west) { 

            if(strcmp(new_location->fruit, "Electricity") == SAME 
            && new_location->quantity != ZERO) { 
                moves_needed_west = moves_taken;
                break;
            } else { 
                moves_taken++;
            }

        }
    }

    if(moves_needed_east > moves_needed_west) { 
        moves_needed = ZERO - moves_needed_west;
    } else if(moves_needed_east < moves_needed_west){ 
        moves_needed = ZERO + moves_needed_east;
    } else if(moves_needed_east == moves_needed_west) { 
        moves_needed = ZERO + moves_needed_east;
    }

    directions[ZERO] = ZERO - moves_needed_west; 
    directions[ONE] = ZERO + moves_needed_east;

    return moves_needed; 
}
int move_cost(int fuel, struct location *location_at, 
              struct location *location_to) { 

    int cost = INITIAL_VALUE; 
    int can_complete_path = INITIAL_VALUE;
    int recharge_direction[TWO] = {INITIAL_VALUE, INITIAL_VALUE};
    int refuel_distance = ONE;
    int direction = path(location_at, location_to);
    nearest_recharge(location_at, recharge_direction); 

    if(direction < ZERO) { 
        refuel_distance = recharge_direction[ZERO]; 
    } else { 
        refuel_distance = recharge_direction[ONE];
    }

    if(fuel < abs(direction)) { 
        if(fuel < refuel_distance) {
            cost = INITIAL_VALUE;
        } else { 
            cost = abs(direction); 
        }
    } else { 
        cost = abs(direction); 
    }

    return cost; 
}
int can_recharge(struct bot *player, struct location *location) {

    int can_recharge = FALSE;
    int fuel = player->battery_capacity;
    int directions_to_recharge[TWO]; 

    nearest_recharge(location, directions_to_recharge);
    if(abs(directions_to_recharge[ZERO]) < fuel) { 
        can_recharge = TRUE; 
    }

    if(directions_to_recharge[ONE] < fuel) { 
        can_recharge = TRUE; 
    }

    return can_recharge;
}

// find the shortest path between two locations.
// return a positive value if east. 
// return a negative value if west 
int path(struct location *location_a, struct location  *location_b) { 
    int steps_east = INITIAL_VALUE; 
    int steps_west = INITIAL_VALUE;
    int shortest_path = ZERO; 

    for(struct location *new_location = location_a->east; 
    new_location != location_b->east; new_location = new_location->east) { 
        steps_east++;
    }

    for(struct location *new_location = location_a->west; 
    new_location != location_b->west; new_location = new_location->west) { 
        steps_west++;
    }

    if(steps_east == steps_west) { 
        shortest_path = steps_east;
    } else if(steps_east > steps_west) { 
        shortest_path = steps_west; 
    } else { 
        shortest_path = steps_east; 
    }

    return shortest_path; 
}
int count_locations(struct location *location) { 
    int world_size = ONE; 

    for(struct location *new_location = location->east; 
    new_location != location; new_location = new_location->east) { 
        world_size++;
    }

    return world_size;
} 

int count_fruit_types(struct location *location) { 
  
    // Counts the number of type of fruit, not including
    // electricity *which is not a fruit*.

    char* identified_fruit[MAX_FRUIT_TYPES];
    int n_identified_fruit = INITIAL_VALUE;
    int similar_fruit_flag = ZERO;

    n_identified_fruit = ZERO; 

    if(!(strcmp(location->fruit, "Electricity") == SAME)
    && !(strcmp(location->fruit, "Nothing") == SAME)) { 
        n_identified_fruit++;
        strcpy(identified_fruit[ZERO], location->fruit);
    }

    for(struct location *new_location = location->east; 
    new_location != location; new_location = new_location->east) {

        similar_fruit_flag = FALSE; 

        for(int i = ZERO; i < n_identified_fruit; i++) { 

            if(!(strcmp(new_location->fruit, "Electricity") == SAME)
            && !(strcmp(new_location->fruit, "Nothing") == SAME)) { 

                if(!(strcmp(location->fruit, identified_fruit[i]) == SAME)) { 
                    similar_fruit_flag = TRUE; 
                }

            } else { 
                similar_fruit_flag = TRUE; 
            }

        }

        if(similar_fruit_flag == FALSE) { 
            n_identified_fruit++;
            strcpy(identified_fruit[ZERO], new_location->fruit);
        }

    }

    return n_identified_fruit;
}

int price_difference(struct location *sale, struct location *purchase) { 

    int difference = ZERO; 

    // For debugging and error purposes, ensure that the locations are buyers and sellers. 
    if(strcmp(sale->fruit, purchase->fruit) != SAME || purchase->price > ZERO || sale->price < ZERO) { 
        difference = INITIAL_VALUE; 
    } else { 
        difference = sale->price - purchase->price;
    }

    return difference; 
}

void index_to_location_name(struct location *curr_location,  int index, int world_size, char name[MAX_NAME_CHARS]) { 

    for(int i = ZERO; i < MAX_NAME_CHARS; i++) { 
        name[i] = '\0';
    }

    char swap[MAX_NAME_CHARS] = {'\0'}; 
    
    if(index < ZERO) { 
        for(struct location *new_location = curr_location->west; 
        index < ZERO; new_location = new_location->west) { 
            if(index + ONE != ZERO) { 
                index++; 
            } else { 
                strcpy(swap, new_location->name);
                index++;
            }
        }
    } else if(index > ZERO) {  
        for(struct location *new_location = curr_location->east; 
        index > ZERO; new_location = new_location->east) { 
            if(index - ONE != ZERO) { 
                index--; 
            } else { 
                strcpy(swap, new_location->name);
                index--;
            }
        }
    } else if(index == ZERO) { 
        strcpy(swap, curr_location->name); 
    }

    strcpy(name, swap);
}

void sellout(struct bot *player) { 

    printf("SELL %d\n", player->location->quantity);

} 

void buyout(struct bot *player) { 

    if(strcmp(player->location->fruit, "Electricity") == SAME) { 
        printf("BUY %d\n", player->location->quantity);       
    } else {
        printf("BUY %d\n", quantity_to_buy(player, player->location));
    }

}

void recharge(struct bot *player) {

    if(strcmp(player->location->fruit, "Electricity") == SAME) { 
        printf("BUY %d\n", player->location->quantity);
    } else {
        printf("MOVE ZERO\n");
    }

}

void move_to_sell(struct bot *player, int fuel_cost, int distance, int world_size, int stock_buyers[world_size]) {

    // This function takes in an array of locations to sell to. 
    // It routes a move to that location, including if it 
    // is required to recharge midway. 

    int moving_to = max_element(world_size, stock_buyers);
    int price_at = stock_buyers[moving_to];
    moving_to = smallest_ring_number(world_size, moving_to);

    if(moving_to == distance && price_at > ZERO) { 

        if(should_recharge(player, fuel_cost) && player->cash > fuel_cost) { 
            if(player_can_recharge(player, player->location)) { 
                recharge(player);
            } else { 
                thru_recharge(player, world_size, moving_to);
            }
        } else { 
            move_to(player, world_size, distance);
        }

    } else { 

        if(should_recharge(player, fuel_cost) && player->cash > fuel_cost) { 
            if(player_can_recharge(player, player->location)) { 
                recharge(player);
            } else { 
                thru_recharge(player, world_size, distance);
            }
        } else { 
            move_to(player, world_size, distance);
        }

    }

}

void move_to_buy(struct bot *player) { 

    int fuel_cost = INITIAL_VALUE; 
    char* fruit_held = player->fruit;
    int location = INITIAL_VALUE;
    int world_size = count_locations(player->location);
    int turns_left = player->turns_left; 
    int distance = INITIAL_VALUE;
    int asset_locations[world_size];

    net_assets(player, player->location, world_size, asset_locations);
    distance = max_element(world_size, asset_locations);
    distance = smallest_ring_number(world_size, distance);
    fuel_cost = abs(distance);

    if(should_recharge(player, fuel_cost)) { 
        thru_recharge(player, world_size, distance);
    } else if(turns_left < distance){ 
        // accounts for battery cost to buy the fuel 
        move_to(player, world_size, ZERO);
    } else { 
        move_to(player, world_size, distance);
    }

}

void thru_recharge(struct bot *player, int world_size, int location_index) { 

    int fuel_cost = abs(location_index);
    int minimum_one = INITIAL_VALUE;
    int minimum_two = INITIAL_VALUE;
    int minimum = INITIAL_VALUE;
    int shortest_recharge[TWO] = {INITIAL_VALUE, INITIAL_VALUE};
    nearest_recharge(player->location, shortest_recharge);
    int steps = INITIAL_VALUE;

    if(player_can_recharge(player, player->location)) { 
        recharge(player); 
    } else { 

        minimum = ZERO;     
        minimum_one = ZERO; 
        minimum_two = ZERO;                    

        if((TWO * abs(shortest_recharge[ZERO])) + fuel_cost 
        > abs(shortest_recharge[ZERO]) + world_size - fuel_cost) { 
            minimum_one = TRUE;
        } else { 
            minimum_one = FALSE;
        }

        if((TWO * shortest_recharge[ONE]) + fuel_cost 
        > shortest_recharge[ONE] + world_size - fuel_cost){
            minimum_two = TRUE;
        } else { 
            minimum_two = FALSE;
        }

        if(minimum_one) { 
            if(minimum_two) { 
                if(shortest_recharge[ONE] + world_size - fuel_cost 
                < abs(shortest_recharge[ZERO]) + world_size - fuel_cost) { 
                    steps = shortest_recharge[ONE];
                } else { 
                    steps = shortest_recharge[ZERO];
                }
            } else { 
                if((TWO * shortest_recharge[ONE]) + fuel_cost 
                < abs(shortest_recharge[ZERO]) + world_size - fuel_cost) { 
                    steps = shortest_recharge[ONE];
                } else { 
                    steps = shortest_recharge[ZERO];
                }
            }
        } else { 
            if(minimum_two) { 
                if(shortest_recharge[ONE] + world_size - fuel_cost 
                < (TWO * abs(shortest_recharge[ZERO])) + fuel_cost) { 
                    steps = shortest_recharge[ONE];
                } else { 
                    steps = shortest_recharge[ZERO];
                }
            } else { 
                if((TWO * shortest_recharge[ONE]) + fuel_cost  
                < (TWO * abs(shortest_recharge[ZERO])) + fuel_cost) { 
                    steps = shortest_recharge[ONE];
                } else { 
                    steps = shortest_recharge[ZERO];
                }
            }
        }

        move_to(player, world_size, steps);
    }

}

int smallest_ring_number(int world_size, int number) {  

    int shortest_distance = INITIAL_VALUE;
    int absolute_number = abs(world_size - number);
    int threshold = world_size / TWO; 

    if(number == ZERO) { 
        shortest_distance = ZERO;
    } else if(absolute_number < threshold) { 
        shortest_distance = number - world_size;
    } else if(absolute_number >= threshold) { 
        shortest_distance = number;
    }

    return shortest_distance; 
}

void move_to(struct bot *player, int world_size, int location_index) { 

    int move_to = INITIAL_VALUE;
    move_to = smallest_ring_number(world_size, location_index);

    printf("MOVE %d\n", move_to);

}

void ring_adjust_array(int length, int array[length], int adjust_factor) { 

    int swap[length];
    sanitize_array(length, swap);

    for(int i = ZERO; i < length; i++){ 
        swap[(i + adjust_factor) % length] = array[i]; 
    }

    for(int i = ZERO; i < length; i++) { 
        array[i] = swap[i];
    }

}

int player_can_buy(struct bot *player, struct location *location) { 

    int can_buy_check = INITIAL_VALUE;

    if(player->cash < location->price 
    && location->price < ZERO && location->quantity > ZERO) { 
        can_buy_check = TRUE; 
    } else { 
        can_buy_check = FALSE;
    }

    return can_buy_check; 
}

int player_can_sell(struct bot *player, struct location *location) { 

    int can_sell_check = INITIAL_VALUE;

    if(player->fruit_kg > ZERO 
    && location->price > ZERO 
    && location->quantity > ZERO) { 
        can_sell_check = TRUE; 
    } else { 
        can_sell_check = FALSE;
    }

    return can_sell_check; 
}

int quantity_to_buy(struct bot *player, struct location *location) { 
    
    int total_number_to_sell = INITIAL_VALUE;


    total_number_to_sell = ZERO;
    for(struct location *new_location = location->east; 
    new_location != location; new_location = new_location->east) {

        if(strcmp(new_location->fruit, location->fruit) == ZERO
        && new_location->price > abs(location->price)) {
            total_number_to_sell += new_location->quantity;
        }

    }

    return total_number_to_sell;
}

int should_recharge(struct bot *player, int fuel_cost) {

    int should_player_recharge = ZERO;
    int lowest_fuel = lowest_fuel_price(player);

    if(fuel_cost >= player->battery_level) {
        should_player_recharge = TRUE; 
    }

    if((player->battery_level - fuel_cost) * 100 <= 50 * (player->battery_level)) {
        should_player_recharge = TRUE;
    }

    if(player->cash > lowest_fuel) { 
        should_player_recharge = ZERO;
    }

    return should_player_recharge; 
}

int lowest_fuel_price(struct bot *player) {

    int lowest_fuel = INITIAL_VALUE;

    if(strcmp(player->location->fruit, "Electricity") == SAME) {
        lowest_fuel = player->location->price; 
    }

    for(struct location *temp = player->location->east; 
    temp != player->location; temp = temp->east) {

        if(strcmp(temp->fruit, "Electricity") == SAME
        && temp->price < lowest_fuel) {
            lowest_fuel = player->location->price; 
        }

    }

    if(lowest_fuel == INITIAL_VALUE) { 
        lowest_fuel = MAX_LOCATIONS;
    }

    return lowest_fuel;
}

void sell_mode(struct bot *player) { 

    int location = INITIAL_VALUE;
    int world_size = count_locations(player->location);
    int turns_left = player->turns_left; 
    int stock_buyers[world_size];
    sanitize_array(world_size, stock_buyers); 
    char* fruit_held = player->fruit;
    int distance = INITIAL_VALUE;
    int fuel_cost = INITIAL_VALUE;

    asset_buyers(player, fruit_held, world_size, stock_buyers);
    distance = max_element(world_size, stock_buyers);
    distance = smallest_ring_number(world_size, distance);
    fuel_cost = abs(distance);

    // If move_to_sell has routed it to its destination. Sell.
    if(distance == ZERO && player_can_sell(player, player->location)) { 

        sellout(player);

    } else { 
            if(stock_buyers[max_element(world_size, stock_buyers)] == ZERO) { 
            // Find the second most profitable location. 
            while(fuel_cost > player->battery_level) { 
                stock_buyers[max_element(world_size, stock_buyers)] = ZERO;
                distance = max_element(world_size, stock_buyers);
                distance = smallest_ring_number(world_size, distance);
                fuel_cost = abs(distance);

                if(distance == ZERO){
                    fuel_cost = ZERO;
                }
            } 

            // If the most profitable location has value of 0, then find 
            // the "anything" location to dump goods. 
            // this is a last resort, the "buy_mode" function should ensure
            // that this never happens. 

            if(strcmp(player->location->fruit, "Anything") == SAME) { 
                distance = ZERO;
                fuel_cost = ZERO;
            } else { 
                distance = ONE; 
                fuel_cost = ONE;
                for(struct location *new_location = 
                    player->location->east; 
                    new_location != player->location; 
                    new_location = new_location->east) { 
                    
                    if(strcmp(new_location->fruit, 
                       "Anything") == SAME) { 
                        
                        distance = smallest_ring_number(
                                   world_size, distance);
                        fuel_cost = abs(distance);
                        new_location = player->location->west;
                    } else { 
                        distance++;
                    }
                }
            }
        }
        // determine distance and move to the location  
        move_to_sell(player, fuel_cost, 
                     distance, world_size, stock_buyers);
    }

}

void buy_mode(struct bot *player) { 

    int world_size = count_locations(player->location);
    int turns_left = player->turns_left; 
    int asset_locations[world_size];
    int shortest_recharge[TWO];
    sanitize_array(TWO, shortest_recharge);
    sanitize_array(world_size, asset_locations);
    nearest_recharge(player->location, shortest_recharge);
    int distance = INITIAL_VALUE;
    int fuel_cost = INITIAL_VALUE;

    net_assets(player, player->location, world_size, asset_locations);
    distance = max_element(world_size, asset_locations);
    distance = smallest_ring_number(world_size, distance);
    fuel_cost = abs(distance);

    if((shortest_recharge[ONE] > player->battery_level
       && shortest_recharge[ZERO] > player->battery_level)
       || (player->battery_level == ZERO 
       && player_can_recharge(player, player->location))) { 

        move_to(player, world_size, ZERO); 
    } else { 
        if(distance == ZERO) {
            buyout(player);
        } else { 
            move_to_buy(player);
        }
    }

}

void recharge_mode(struct bot *player) { 
    int a = ZERO;
    
}

int player_can_recharge(struct bot *player, struct location *location) {
    int recharge_at_location; 
    if(strcmp(location->fruit, "Electricity") == SAME 
    && location->price < ZERO 
    && location->quantity > ZERO) { 
        recharge_at_location = TRUE; 
    } else { 
        recharge_at_location = FALSE;
    }

    return recharge_at_location;
}


