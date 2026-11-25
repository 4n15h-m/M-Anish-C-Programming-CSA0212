#include <stdio.h>

int main()
{
    int mark;

    printf("Enter marks (-1 to stop): ");
    scanf("%d", &mark);

    while(mark != -1)
    {
        printf("Entered mark: %d\n", mark);
        printf("Enter marks (-1 to stop): ");
        scanf("%d", &mark);
    }

    return 0;
}
