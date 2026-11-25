#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n1. Display Records");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
    } while(choice != 2);

    return 0;
}
