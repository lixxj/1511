#include <stdio.h>

int main()
{
    int nbword = 1;
    char c, prvc = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            nbword++;
        }
        if(c == prvc && prvc == ' ')
            nbword--;
        if(c == '\n')
        {
            printf("%d\n", nbword);
            nbword = 1;
        }
        prvc = c;
    }
    return 0;
}
