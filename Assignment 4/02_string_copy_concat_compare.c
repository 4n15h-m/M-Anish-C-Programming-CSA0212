#include <stdio.h>
#include <string.h>

int main(void)
{
    char title[100] = "The Alchemist";
    char copy[100];
    char author[50] = "Paulo Coelho";
    char label[160] = "";

    strcpy(copy, title);
    printf("Copied Title: %s\n", copy);

    strcat(label, title);
    strcat(label, " by ");
    strcat(label, author);
    printf("%s\n", label);

    if (strcmp(title, copy) == 0)
        printf("Both Titles Are Equal\n");
    else
        printf("Titles Are Different\n");

    return 0;
}
