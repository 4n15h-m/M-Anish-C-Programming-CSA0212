#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[100];
};

int main(void)
{
    int n;
    printf("Enter Number of Books: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid Number of Books\n");
        return 1;
    }

    struct Book *books = malloc((size_t)n * sizeof *books);
    if (books == NULL) {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Book ID: ");
        if (scanf("%d", &books[i].id) != 1) {
            free(books);
            return 1;
        }
    }

    printf("\nBook Records:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", books[i].id);

    free(books);
    return 0;
}
