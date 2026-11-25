#include <stdio.h>

struct Data {
    int id;
    float marks;
    char code[20];
};

union DataUnion {
    int id;
    float marks;
    char code[20];
};

int main(void)
{
    printf("Structure Size: %zu bytes\n", sizeof(struct Data));
    printf("Union Size: %zu bytes\n", sizeof(union DataUnion));
    return 0;
}
