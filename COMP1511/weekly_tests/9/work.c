#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned long c;
    unsigned long line;
    unsigned long word;
    char ch;
    char lastch = -1;

    c = 0;
    line = 0;
    word = 0;

    while((ch = getchar()) != EOF)
    {
        c ++;
        if (ch == '\n')
        {
            line ++;
        }
        if (ch == ' ' || ch == '\n' || ch =='\'')
        {
            if (!(lastch == ' ' && ch == ' '))
            {
                word ++;
            }
        }
        lastch = ch;
    }
    printf( "%lu %lu %lu\n", c, word, line );
    return 0;
}
