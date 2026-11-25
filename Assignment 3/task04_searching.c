#include <stdio.h>
#define STUDENTS 3
#define SUBJECTS 3

int main()
{
    int id[STUDENTS] = {101, 102, 103};
    int marks[STUDENTS][SUBJECTS] =
    {
        {80, 75, 90},
        {70, 85, 75},
        {90, 80, 95}
    };

    int searchID, searchMark;
    int i, j, found = 0;
    int max, topper;

    printf("Enter Student ID: ");
    scanf("%d", &searchID);

    for(i = 0; i < STUDENTS; i++)
    {
        if(id[i] == searchID)
        {
            printf("Student Found!\n");
            for(j = 0; j < SUBJECTS; j++)
                printf("Subject %d: %d\n", j + 1, marks[i][j]);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Student Not Found!\n");

    printf("\nEnter mark to search: ");
    scanf("%d", &searchMark);

    found = 0;
    for(i = 0; i < STUDENTS; i++)
    {
        for(j = 0; j < SUBJECTS; j++)
        {
            if(marks[i][j] == searchMark)
            {
                printf("Found at Student %d, Subject %d\n",
                       i + 1, j + 1);
                found = 1;
            }
        }
    }

    if(!found)
        printf("Mark Not Found!\n");

    printf("\nSubject-wise Toppers:\n");
    for(j = 0; j < SUBJECTS; j++)
    {
        max = marks[0][j];
        topper = 0;
        for(i = 1; i < STUDENTS; i++)
        {
            if(marks[i][j] > max)
            {
                max = marks[i][j];
                topper = i;
            }
        }
        printf("Subject %d: Student %d - %d marks\n",
               j + 1, topper + 1, max);
    }

    return 0;
}
