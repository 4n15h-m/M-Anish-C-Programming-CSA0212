#include <stdio.h>

void counter(void)
{
    static int count = 0;
    count++;
    printf("Count = %d\n", count);
}

int totalBooks = 100;

int main(void)
{
    auto int localCount = 10;
    extern int totalBooks;
    register int i;

    printf("Local Count: %d\n", localCount);
    printf("Total Books: %d\n", totalBooks);

    for (i = 1; i <= 5; i++)
        printf("%d ", i);
    printf("\n");

    counter();
    counter();
    counter();
    return 0;
}
