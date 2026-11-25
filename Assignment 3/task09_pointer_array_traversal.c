#include <stdio.h>

int main()
{
    int marks[] = {80, 75, 90, 85};
    int *ptr = marks;
    int i;

    printf("Student Marks:\n");
    for(i = 0; i < 4; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
