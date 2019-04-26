// Written by XJ LI

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "fruit_bot.h"

int nearest_electricity(struct bot *b);

int main(int argc, char *argv[]) {
    struct bot *me = fruit_bot_input(stdin);

    int distance = nearest_electricity(me);
    printf("Distance to nearest available electricity is %d\n", distance);

    return 0;
}


// return distance to nearest electricity
// if nearest electricity is west return negative int
// if nearest electricity is current location return 0

int nearest_electricity(struct bot *b) {
    int dist;
    int distW = 0;
    int distE = 0;
    struct location *currW = b->location;
    struct location *currE = b->location;
    if (strcmp("Electricity", currW->fruit) == 0 || strcmp("Electricity", currE->fruit) == 0) {
        dist = 0;
        return dist;
    }
    currW = currW->west;
    currE = currE->east;
    while (currW != b->location) {
        distW++;
        if (strcmp("Electricity", currW->fruit) == 0) {
            break;
        }
        currW = currW->west;
    }
    while (currE != b->location) {
        distE++;
        if (strcmp("Electricity", currE->fruit) == 0) {
            break;
        }
        currE = currE->east;
    }
    if (distW <= distE) {
        dist = -distW;
    } else {
        dist = distE;
    }
    return dist;
}
