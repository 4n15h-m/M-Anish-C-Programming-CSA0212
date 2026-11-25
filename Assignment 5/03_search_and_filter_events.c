#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char line[200];
    int key, id, found = 0;

    printf("Enter Event ID: ");
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Invalid event ID\n");
        return 1;
    }

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("File error");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d,", &id) == 1 && id == key) {
            printf("Event Found: %s", line);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Event Not Found\n");

    rewind(fp);
    printf("\nLAB EVENTS\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, ",LAB,") != NULL)
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}
