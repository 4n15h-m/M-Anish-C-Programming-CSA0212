#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char text[100];
    char *p;
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Enter Text: ");
    if (fgets(text, sizeof text, stdin) == NULL)
        return 1;

    for (p = text; *p != '\0'; p++) {
        if (isalpha((unsigned char)*p)) {
            char ch = (char)tolower((unsigned char)*p);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit((unsigned char)*p)) {
            digits++;
        } else if (*p == ' ') {
            spaces++;
        }
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Digits = %d\n", digits);
    printf("Spaces = %d\n", spaces);
    return 0;
}
