// Written by XJ LI
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <species_names_file> <old_file> <new_file>\n", argv[0]);
        return 1;
    }
    
    int a = getchar();
    while (a != EOF) {
        if (a >= '0' && a <= '9') {
            int index_a = a - 48;
            a = argv[1][index_a];
        }
        printf("%c", a);
        a = getchar();
    }
    
    return 0;
}
