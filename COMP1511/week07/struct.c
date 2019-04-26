#include <stdio.h>
#include <string.h>

#define N_STUDENTS 1087
#define MAX_NAME_LEN 64

typedef struct _ferdian {
    int studentID;
    char name[MAX_NAME_LEN];
    int tutorial;
    int ass1_mark;
} newtype;

newtype readStudent (void);

int main (void) {
    newtype b = readStudent();
    
    printf ("StudentID    %d\n", b.studentID);
    printf ("Name         %s\n", b.name);
    printf ("Tutorial     %d\n", b.tutorial);
    printf ("ass1 mark    %d\n", b.ass1_mark);

    return 0;
}

newtype readStudent (void) {
    newtype s;
    printf ("StudentID    ");
    scanf ("%d", &(s.studentID));
    getchar ();
    printf ("Name         ");
    fgets (s.name, MAX_NAME_LEN, stdin);
    printf ("Tutorial     ");
    scanf ("%d", &(s.tutorial));
    printf ("ass1 mark    ");
    scanf ("%d", &(s.ass1_mark));
    return s;
}


