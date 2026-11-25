#include <stdio.h>

void changeValue(int *x)
{
    *x = 100;
}

int main()
{
    int a = 50;
    changeValue(&a);
    printf("Value of a = %d", a);
    return 0;
}
