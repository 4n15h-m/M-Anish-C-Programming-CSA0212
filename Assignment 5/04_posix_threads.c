#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *countEvents(void *arg)
{
    FILE *fp;
    char line[200];
    int count = 0;
    (void)arg;

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("Thread 1 file error");
        return NULL;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        count++;

    fclose(fp);
    printf("Thread 1: Total Events = %d\n", count);
    return NULL;
}

void *latestEvent(void *arg)
{
    FILE *fp;
    char line[200], last[200] = "";
    (void)arg;

    fp = fopen("events.txt", "r");
    if (fp == NULL) {
        perror("Thread 2 file error");
        return NULL;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        snprintf(last, sizeof(last), "%s", line);

    fclose(fp);
    printf("Thread 2: Latest Event = %s", last);
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, countEvents, NULL) != 0) {
        fprintf(stderr, "Thread 1 creation failed\n");
        return 1;
    }

    if (pthread_create(&t2, NULL, latestEvent, NULL) != 0) {
        fprintf(stderr, "Thread 2 creation failed\n");
        pthread_join(t1, NULL);
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("All Threads Completed\n");
    return 0;
}
