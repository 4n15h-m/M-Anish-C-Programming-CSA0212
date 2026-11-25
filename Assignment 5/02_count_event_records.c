#include <stdio.h>

int main(void)
{
    FILE *fp;
    char line[200];
    int count = 0;

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("File error");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        count++;

    printf("Total Events = %d\n", count);
    fclose(fp);
    return 0;
}
