#include <stdio.h>
#include <string.h>

enum IDType { NUMERIC, TEXT };

union Identifier {
    int number;
    char code[20];
};

struct BookID {
    enum IDType type;
    union Identifier value;
};

int main(void)
{
    struct BookID id;

    id.type = NUMERIC;
    id.value.number = 101;
    if (id.type == NUMERIC)
        printf("Numeric ID: %d\n", id.value.number);

    id.type = TEXT;
    strcpy(id.value.code, "LIB101");
    if (id.type == TEXT)
        printf("Text ID: %s\n", id.value.code);

    return 0;
}
