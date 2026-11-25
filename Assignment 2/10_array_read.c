#include <stdio.h>

int main()
{
    int marks[5], i;

    for(i = 0; i < 5; i++)
    {
        printf("Enter mark: ");
        scanf("%d", &marks[i]);
    }

    return 0;
}
