#include <stdio.h>

int main(void)
{
    FILE *fp;
    char line[200];

    fp = fopen("events.txt", "w");
    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }

    fprintf(fp, "101,1,09:00,LAB,Experiment Started\n");
    fprintf(fp, "102,2,10:00,LIB,Book Issued\n");
    fclose(fp);

    fp = fopen("events.txt", "a");
    if (fp == NULL) {
        perror("File append failed");
        return 1;
    }

    fprintf(fp, "103,3,11:00,ENTRY,Student Entered\n");
    fclose(fp);

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("File reading failed");
        return 1;
    }

    printf("CAMPUS EVENT LOG\n");
    while (fgets(line, sizeof(line), fp) != NULL)
        printf("%s", line);

    fclose(fp);
    return 0;
}
