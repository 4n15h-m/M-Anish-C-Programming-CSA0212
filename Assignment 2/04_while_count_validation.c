#include <stdio.h>

int main()
{
    int n;

    printf("Enter student count: ");
    scanf("%d", &n);

    while(n < 1 || n > 100)
    {
        printf("Invalid count. Enter again: ");
        scanf("%d", &n);
    }

    printf("Valid student count: %d", n);

    return 0;
}
