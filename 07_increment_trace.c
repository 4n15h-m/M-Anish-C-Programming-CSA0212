#include <stdio.h>

int main()
{
    int x = 5;

    printf("Initial: %d\n", x);
    printf("Prefix: %d\n", ++x);
    printf("Postfix: %d\n", x++);
    printf("Final: %d\n", x);

    return 0;
}
