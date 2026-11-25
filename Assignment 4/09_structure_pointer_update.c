#include <stdio.h>

struct Book {
    int id;
    char title[50];
    int availability;
};

void update(struct Book *b)
{
    b->availability = 0;
}

int main(void)
{
    struct Book b1 = {101, "C Programming", 1};
    update(&b1);

    printf("Book ID: %d\n", b1.id);
    printf("Availability: %d\n", b1.availability);
    return 0;
}
