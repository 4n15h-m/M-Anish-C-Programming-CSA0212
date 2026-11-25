#include <stdio.h>

int main()
{
    int mark;
    float attendance;

    printf("Enter attendance: ");
    scanf("%f", &attendance);

    printf("Enter internal mark: ");
    scanf("%d", &mark);

    if (attendance >= 75)
    {
        if (mark >= 40)
        {
            printf("Eligible for Examination");
        }
        else
        {
            printf("Low Internal Marks");
        }
    }
    else
    {
        printf("Attendance Shortage");
    }

    return 0;
}
