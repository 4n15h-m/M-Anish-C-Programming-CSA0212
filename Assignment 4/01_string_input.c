#include <stdio.h>
#include <string.h>

int main(void)
{
    char title[100];

    printf("Enter Book Title: ");
    if (fgets(title, sizeof title, stdin) == NULL)
        return 1;

    title[strcspn(title, "\n")] = '\0';

    if (strlen(title) == 0)
        printf("Invalid Empty Title\n");
    else {
        printf("Book Title: %s\n", title);
        printf("Length: %zu\n", strlen(title));
    }
    return 0;
}
