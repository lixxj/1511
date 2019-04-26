// using functions to save effort

#include <stdio.h>

void print_hundred_messages(void);
void print_ten_messages(void);
void print_message(void);

int main(void)
{
    print_hundred_messages();
    return 0;
}

void print_hundred_messages(void) {
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
    print_ten_messages();
}

void print_ten_messages(void) {
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
    print_message();
}

void print_message() {
    printf("C is good.  ");
    printf("C is great.  ");
    printf("We all love C.\n");
}


