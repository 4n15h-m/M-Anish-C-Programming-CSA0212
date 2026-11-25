#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[100], temp;
    int i, j;

    printf("Enter String: ");
    if (fgets(text, sizeof text, stdin) == NULL)
        return 1;

    text[strcspn(text, "\n")] = '\0';
    i = 0;
    j = (int)strlen(text) - 1;

    while (i < j) {
        temp = text[i];
        text[i] = text[j];
        text[j] = temp;
        i++;
        j--;
    }

    printf("Reversed String: %s\n", text);
    return 0;
}
