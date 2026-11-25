#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char line[200];
    char start[] = "09:00";
    char end[] = "12:00";
    char time[10];
    int id, source, count = 0;

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("File error");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d,%d,%9[^,]", &id, &source, time) != 3)
            continue;

        if (strcmp(time, start) >= 0 && strcmp(time, end) <= 0)
            count++;
    }

    printf("Matching Events: %d\n", count);
    fclose(fp);
    return 0;
}
