// Written by XJ LI

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "fruit_bot.h"

void print_world(struct bot *b);

int main(void) {
    struct bot *b = fruit_bot_input(stdin);
    print_world(b);
    return 0;
}

// print details of all locations in the Fruit Bot world
// starting from bot's current location and going east
void print_world(struct bot *b) {
    struct location *curr = b->location;
    printf("%s: ", curr->name);
    if (strcmp(curr->fruit, "Nothing") == 0) {
        printf("other\n");
    } else {
        if (curr->price > 0) {
            printf("will buy ");
        } else {
            printf("will sell ");
        }
        if (strcmp(curr->fruit, "Electricity") == 0) {
            printf("%d kJ of ", curr->quantity);
        } else {
            printf("%d kg of ", curr->quantity);
        }
        printf("%s for $%d\n", curr->fruit, abs(curr->price));
    }
    
    curr = curr->east;
    
    while (curr != b->location) {
        printf("%s: ", curr->name);
        if (strcmp(curr->fruit, "Nothing") == 0) {
            printf("other\n");
        } else {
            if (curr->price > 0) {
                printf("will buy ");
            } else {
                printf("will sell ");
            }
            if (strcmp(curr->fruit, "Electricity") == 0) {
                printf("%d kJ of ", curr->quantity);
            } else {
                printf("%d kg of ", curr->quantity);
            }
            printf("%s for $%d\n", curr->fruit, abs(curr->price));
        }
        curr = curr->east;
    }
    
}
