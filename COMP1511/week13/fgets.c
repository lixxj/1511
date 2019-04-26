#include <stdio.h>
#include <assert.h>

#define MAX_LINE_CHARS 256
int main(void) {
    char line[MAX_LINE_CHARS] = {0};
    fgets(line, MAX_LINE_CHARS, stdin);
    int i = 0;
    
    printf("%s", line);
    return 0;
}
