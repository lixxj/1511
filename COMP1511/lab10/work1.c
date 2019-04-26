#include<stdio.h>

int main(void) {
    printf("%2d\n", 3);
    printf("%02d\n", 4);

    return 0;
}







// Print out the merged list for debugging
    struct pod *curr1 = first_pod;
    while (curr1 != NULL) {
        printf("%02d/%02d/%02d ", curr1->when->day, curr1->when->month, curr1->when->year);
        printf("%2d ", curr1->how_many);
        printf("%s\n", curr1->species);
        curr1 = curr1->next;
    }
