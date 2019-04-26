// Written by XJ LI

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_even(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked linked from command line arguments
    struct node *head = NULL;
    int arg = argc - 1;
    while (arg > 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(argv[arg]);
        head = n;
        arg = arg - 1;
    }

    int result = count_even(head);
    printf("%d\n", result);

    return 0;
}


// return the number of even values in a linked list
int count_even(struct node *head) {
    int even = 0;
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            even++;
        }
        curr = curr->next;
    }
    return even;

}
