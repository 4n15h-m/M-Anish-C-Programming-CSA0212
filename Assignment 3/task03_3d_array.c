#include <stdio.h>
#define STUDENTS 2
#define ASSESSMENTS 2
#define SUBJECTS 3

int main()
{
    int marks[STUDENTS][ASSESSMENTS][SUBJECTS];
    int i, j, k, total;
    float average;

    for(i = 0; i < STUDENTS; i++)
    {
        for(j = 0; j < ASSESSMENTS; j++)
        {
            printf("\nStudent %d - Assessment %d\n", i + 1, j + 1);
            for(k = 0; k < SUBJECTS; k++)
            {
                printf("Subject %d: ", k + 1);
                scanf("%d", &marks[i][j][k]);

                if(marks[i][j][k] < 0 ||
                   marks[i][j][k] > 100)
                {
                    printf("Invalid marks!\n");
                    return 1;
                }
            }
        }
    }

    for(i = 0; i < STUDENTS; i++)
    {
        total = 0;
        printf("\nStudent %d Results:\n", i + 1);
        for(j = 0; j < ASSESSMENTS; j++)
        {
            printf("Assessment %d: ", j + 1);
            for(k = 0; k < SUBJECTS; k++)
            {
                printf("%d ", marks[i][j][k]);
                total += marks[i][j][k];
            }
            printf("\n");
        }
        average = total / (float)(ASSESSMENTS * SUBJECTS);
        printf("Total = %d\n", total);
        printf("Average = %.2f\n", average);
    }

    for(j = 0; j < ASSESSMENTS; j++)
    {
        total = 0;
        for(i = 0; i < STUDENTS; i++)
        {
            for(k = 0; k < SUBJECTS; k++)
                total += marks[i][j][k];
        }
        printf("\nAssessment %d Average = %.2f\n",
               j + 1,
               total / (float)(STUDENTS * SUBJECTS));
    }

    return 0;
}
