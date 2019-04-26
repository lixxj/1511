#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_repeated(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_repeated(head);
    print_list(new_head);

    return 0;
}


// Delete any consecutive nodes with repeated values from the linked list.
// The deleted node is freed.
// If there are no consecutive nodes with repeated values, the list is
// not changed.
// The head of the list is returned.

struct node *delete_repeated(struct node *head) {
    if (head == NULL) {
        return head;
    }
    struct node *prev = head;
    struct node *curr = head->next;
    int flag = 0;
    while (curr != NULL) {
        flag = 0;
        if (prev->data == curr->data) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
            flag = 1;
        }
        if (flag == 0) {
            prev = prev->next;
            curr = curr->next;
        }
    }
    
    return head;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
         printf("%d", n->data);
         if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}


