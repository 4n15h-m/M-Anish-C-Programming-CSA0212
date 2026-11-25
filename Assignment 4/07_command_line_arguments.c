#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage:\n");
        printf("library add\n");
        printf("library list\n");
        printf("library search <book_id>\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        printf("Add Book Operation Selected\n");
    } else if (strcmp(argv[1], "list") == 0) {
        printf("Displaying Library Records\n");
    } else if (strcmp(argv[1], "search") == 0) {
        if (argc != 3) {
            printf("Usage: library search <book_id>\n");
            return 1;
        }

        char *end;
        errno = 0;
        long id = strtol(argv[2], &end, 10);

        if (errno != 0 || *end != '\0' || id <= 0 || id > INT_MAX) {
            printf("Invalid Book ID\n");
            return 1;
        }
        printf("Searching Book ID: %ld\n", id);
    } else {
        printf("Invalid Command\n");
    }
    return 0;
}
