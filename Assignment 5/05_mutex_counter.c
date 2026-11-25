#include <stdio.h>
#include <pthread.h>

#define THREADS 4
#define ITERATIONS 100000

static int counter = 0;
static pthread_mutex_t lock;

void *increment(void *arg)
{
    (void)arg;

    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[THREADS];

    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }

    for (int i = 0; i < THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0) {
            fprintf(stderr, "Thread creation failed\n");
            for (int j = 0; j < i; j++)
                pthread_join(threads[j], NULL);
            pthread_mutex_destroy(&lock);
            return 1;
        }
    }

    for (int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Final Counter = %d\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}
