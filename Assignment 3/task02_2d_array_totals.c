#include <stdio.h>
#define STUDENTS 3
#define SUBJECTS 3

int main()
{
    int marks[STUDENTS][SUBJECTS];
    int i, j, total;
    float average;

    printf("Enter student marks:\n");
    for(i = 0; i < STUDENTS; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        for(j = 0; j < SUBJECTS; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);

            if(marks[i][j] < 0 || marks[i][j] > 100)
            {
                printf("Invalid marks!\n");
                return 1;
            }
        }
    }

    printf("\nEXAMINATION RESULT\n");
    for(i = 0; i < STUDENTS; i++)
    {
        total = 0;
        for(j = 0; j < SUBJECTS; j++)
        {
            printf("%d\t", marks[i][j]);
            total += marks[i][j];
        }
        average = total / (float)SUBJECTS;
        printf("| Total = %d", total);
        printf(" | Average = %.2f\n", average);
    }

    printf("\nSubject-wise averages:\n");
    for(j = 0; j < SUBJECTS; j++)
    {
        total = 0;
        for(i = 0; i < STUDENTS; i++)
            total += marks[i][j];
        printf("Subject %d Average = %.2f\n",
               j + 1, total / (float)STUDENTS);
    }

    return 0;
}
