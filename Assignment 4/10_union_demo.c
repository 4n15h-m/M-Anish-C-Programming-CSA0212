#include <stdio.h>
#include <string.h>

union BookIdentifier {
    int accession_number;
    char code[20];
};

int main(void)
{
    union BookIdentifier id;

    id.accession_number = 101;
    printf("Accession Number: %d\n", id.accession_number);

    strcpy(id.code, "LIB-A101");
    printf("Book Code: %s\n", id.code);
    return 0;
}
