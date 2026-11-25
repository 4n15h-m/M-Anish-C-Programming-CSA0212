#include <stdio.h>

int main()
{
    int mark[5], i, total = 0;
    int highest, lowest;
    float average;

    for(i = 0; i < 5; i++)
    {
        printf("Enter mark: ");
        scanf("%d", &mark[i]);
        total += mark[i];
    }

    highest = lowest = mark[0];

    for(i = 0; i < 5; i++)
    {
        if(mark[i] > highest)
            highest = mark[i];

        if(mark[i] < lowest)
            lowest = mark[i];
    }

    average = (float)total / 5;

    printf("Total = %d\n", total);
    printf("Average = %.2f\n", average);
    printf("Highest = %d\n", highest);
    printf("Lowest = %d\n", lowest);

    return 0;
}
