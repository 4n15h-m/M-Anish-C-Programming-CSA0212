#include <stdio.h>

#define MAX 100
#define MIN_ATTENDANCE 75
#define PASS_MARK 40

int main()
{
    int id[MAX], marks[MAX];
    float attendance[MAX];
    int n, i, j, choice, key;
    int total, eligible, highest, lowest;
    int above, below, found;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    while(n < 1 || n > MAX)
    {
        printf("Invalid count. Enter 1-100: ");
        scanf("%d", &n);
    }

    /* Reading student records */
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Student ID: ");
        scanf("%d", &id[i]);

        printf("Enter Attendance: ");
        scanf("%f", &attendance[i]);

        while(attendance[i] < 0 || attendance[i] > 100)
        {
            printf("Invalid attendance. Re-enter: ");
            scanf("%f", &attendance[i]);
        }

        printf("Enter Internal Mark: ");
        scanf("%d", &marks[i]);

        while(marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid mark. Re-enter: ");
            scanf("%d", &marks[i]);
        }
    }

    do
    {
        printf("\n===== STUDENT ANALYSIS SYSTEM =====\n");
        printf("1. Display Records\n");
        printf("2. Check Eligibility\n");
        printf("3. Class Statistics\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("6. Merit List\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                for(i = 0; i < n; i++)
                {
                    printf("\nID: %d", id[i]);
                    printf("\nAttendance: %.2f", attendance[i]);
                    printf("\nMark: %d", marks[i]);

                    if(attendance[i] >= 75 &&
                       marks[i] >= 40)
                        printf("\nEligible");
                    else
                        printf("\nNot Eligible");

                    if(marks[i] >= 90)
                        printf("\nExcellent");
                    else if(marks[i] >= 75)
                        printf("\nVery Good");
                    else if(marks[i] >= 60)
                        printf("\nGood");
                    else if(marks[i] >= 40)
                        printf("\nPass");
                    else
                        printf("\nNeeds Improvement");

                    if(attendance[i] >= 75 &&
                       attendance[i] < 80)
                        printf("\nAttendance Warning");

                    printf("\n");
                }
                break;

            case 2:
                printf("Enter Student ID: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(id[i] == key)
                    {
                        found = 1;

                        if(attendance[i] >= 75)
                        {
                            if(marks[i] >= 40)
                                printf("Eligible");
                            else
                                printf("Low Internal Marks");
                        }
                        else
                            printf("Attendance Shortage");

                        break;
                    }
                }

                if(found == 0)
                    printf("Student Not Found");

                break;

            case 3:
                total = 0;
                eligible = 0;
                above = 0;
                below = 0;

                highest = marks[0];
                lowest = marks[0];

                for(i = 0; i < n; i++)
                {
                    total += marks[i];

                    if(attendance[i] >= 75 &&
                       marks[i] >= 40)
                        eligible++;

                    if(marks[i] > highest)
                        highest = marks[i];

                    if(marks[i] < lowest)
                        lowest = marks[i];
                }

                average = (float)total / n;

                for(i = 0; i < n; i++)
                {
                    if(marks[i] > average)
                        above++;
                    else if(marks[i] < average)
                        below++;
                }

                printf("Total: %d", total);
                printf("\nAverage: %.2f", average);
                printf("\nHighest: %d", highest);
                printf("\nLowest: %d", lowest);
                printf("\nEligible Students: %d", eligible);
                printf("\nAbove Average: %d", above);
                printf("\nBelow Average: %d", below);

                break;

            case 4:
                printf("Enter Student ID: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(id[i] == key)
                    {
                        printf("Student Found");
                        printf("\nID: %d", id[i]);
                        printf("\nAttendance: %.2f",
                               attendance[i]);
                        printf("\nMarks: %d", marks[i]);

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Student Not Found");

                break;

            case 5:
                printf("Exiting Program");
                break;

            case 6:
            {
                int sid[MAX], smark[MAX];
                float satt[MAX];
                int tempID, tempMark;
                float tempAttendance;

                for(i = 0; i < n; i++)
                {
                    sid[i] = id[i];
                    smark[i] = marks[i];
                    satt[i] = attendance[i];
                }

                for(i = 0; i < n - 1; i++)
                {
                    for(j = 0; j < n - 1 - i; j++)
                    {
                        if(smark[j] < smark[j + 1])
                        {
                            tempMark = smark[j];
                            smark[j] = smark[j + 1];
                            smark[j + 1] = tempMark;

                            tempID = sid[j];
                            sid[j] = sid[j + 1];
                            sid[j + 1] = tempID;

                            tempAttendance = satt[j];
                            satt[j] = satt[j + 1];
                            satt[j + 1] = tempAttendance;
                        }
                    }
                }

                printf("\nMERIT LIST\n");

                for(i = 0; i < n; i++)
                {
                    printf("\n%d. ID: %d | Mark: %d",
                           i + 1, sid[i], smark[i]);
                }
            }
            break;

            default:
                printf("Invalid Choice");
        }
    } while(choice != 5);

    return 0;
}
