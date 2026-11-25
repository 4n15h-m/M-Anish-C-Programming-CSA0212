#include <stdio.h>

struct Book {
    int id;
    char title[50];
};

int main(void)
{
    struct Book books[3] = {
        {101, "C Programming"},
        {102, "Data Structures"},
        {103, "Operating Systems"}
    };

    for (int i = 0; i < 3; i++)
        printf("%d %s\n", books[i].id, books[i].title);

    return 0;
}
