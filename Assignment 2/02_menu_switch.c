#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\nSTUDENT ANALYSIS SYSTEM\n");
        printf("1. Display Records\n");
        printf("2. Check Eligibility\n");
        printf("3. Class Statistics\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("6. Merit List\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Displaying Records\n");
                break;
            case 2:
                printf("Checking Eligibility\n");
                break;
            case 3:
                printf("Displaying Statistics\n");
                break;
            case 4:
                printf("Searching Student\n");
                break;
            case 5:
                printf("Exiting Program\n");
                break;
            case 6:
                printf("Displaying Merit List\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 5);

    return 0;
}
