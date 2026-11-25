#include <stdio.h>

int main(void)
{
    char text[] = "Library";
    char *ptr = text;

    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}
