#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#define TITLE_SIZE 100
#define NAME_SIZE 50
#define EMAIL_SIZE 100
enum IDType
{
    NUMERIC,
    TEXT
};
union Identifier
{
    int number;
    char code[20];
};
struct Book
{
    int book_id;
    char title[TITLE_SIZE];
    char author[NAME_SIZE];
    int year;
    int availability;
    enum IDType type;


    union Identifier identifier;
};
struct Address
{
    char city[30];
    int pincode;
};
struct Borrowing
{
    int book_id;
    char issue_date[15];
    int returned;
};
struct Member
{
    int member_id;
    char name[NAME_SIZE];
    char email[EMAIL_SIZE];
    char contact[15];
    struct Address address;
    struct Borrowing *history;
    size_t history_count;
};
struct Book *books = NULL;
size_t book_count = 0;
struct Member *members = NULL;
size_t member_count = 0;
/* Safe line input */
int readLine(char *buffer, size_t size)
{
    if(fgets(buffer, size, stdin) == NULL)
    return 0;
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
else
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF)


    ;
}
return 1;
}
/* Valid integer input */
int readInteger(const char *prompt, int *value)
{
    char input[50];
    char *end;
    printf("%s", prompt);
    if(!readLine(input, sizeof(input)))
    return 0;
    errno = 0;
    long result = strtol(input, &end, 10);
    if(input == end || *end != '\0' ||
    errno != 0 || result < 0 || result > INT_MAX)
    {
        return 0;
    }
*value = (int)result;
return 1;
}
/* Search book */
struct Book *searchBook(int id)
{
    for(size_t i = 0; i < book_count; i++)
    {
        if(books[i].book_id == id)
        return &books[i];
    }
return NULL;
}
/* Add book */
void addBook(void)
{
    int id, year;
    char title[TITLE_SIZE];
    char author[NAME_SIZE];


    if(!readInteger("Enter Book ID: ", &id) || id <= 0)
    {
        printf("Invalid Book ID\n");
        return;
    }
if(searchBook(id) != NULL)
{
    printf("Book ID Already Exists\n");
    return;
}
printf("Enter Book Title: ");
if(!readLine(title, sizeof(title)) ||
strlen(title) == 0)
{
    printf("Invalid Title\n");
    return;
}
printf("Enter Author Name: ");
if(!readLine(author, sizeof(author)) ||
strlen(author) == 0)
{
    printf("Invalid Author Name\n");
    return;
}
if(!readInteger("Enter Publication Year: ", &year) ||
year <= 0)
{
    printf("Invalid Year\n");
    return;
}
struct Book *temp =
realloc(books,
(book_count + 1) * sizeof(struct Book));
if(temp == NULL)
{
    printf("Memory Allocation Failed\n");
    return;
}
books = temp;
struct Book *b = &books[book_count];
b->book_id = id;


strcpy(b->title, title);
strcpy(b->author, author);
b->year = year;
b->availability = 1;
b->type = NUMERIC;
b->identifier.number = id;
book_count++;
printf("Book Added Successfully\n");
}
/* Display books */
void listBooks(void)
{
    if(book_count == 0)
    {
        printf("No Books Available\n");
        return;
    }
printf("\nLIBRARY INVENTORY\n");
for(size_t i = 0; i < book_count; i++)
{
    printf("\nBook ID: %d\n", books[i].book_id);
    printf("Title: %s\n", books[i].title);
    printf("Author: %s\n", books[i].author);
    printf("Year: %d\n", books[i].year);
    printf("Availability: %s\n",
    books[i].availability ?
    "Available" : "Borrowed");
}
}
/* Search and display */
void findBook(int id)
{
    struct Book *b = searchBook(id);
    if(b == NULL)
    {
        printf("Book Not Found\n");
        return;
    }
printf("Book ID: %d\n", b->book_id);


printf("Title: %s\n", b->title);
printf("Author: %s\n", b->author);
printf("Year: %d\n", b->year);
}
/* Update availability */
void updateAvailability(int id, int status)
{
    struct Book *b = searchBook(id);
    if(b == NULL)
    {
        printf("Book Not Found\n");
        return;
    }
b->availability = status;
printf("Availability Updated\n");
}
/* Add member */
void addMember(void)
{
    int id;
    struct Member *temp;
    if(!readInteger("Enter Member ID: ", &id) || id <= 0)
    {
        printf("Invalid Member ID\n");
        return;
    }
for(size_t i = 0; i < member_count; i++)
{
    if(members[i].member_id == id)
    {
        printf("Member ID Already Exists\n");
        return;
    }
}
temp = realloc(members,
(member_count + 1) * sizeof(struct Member));
if(temp == NULL)
{
    printf("Memory Allocation Failed\n");
    return;
}


members = temp;
struct Member *m = &members[member_count];
m->member_id = id;
printf("Enter Member Name: ");
if(!readLine(m->name, sizeof(m->name)) ||
strlen(m->name) == 0)
return;
printf("Enter Email: ");
if(!readLine(m->email, sizeof(m->email)))
return;
printf("Enter Contact: ");
if(!readLine(m->contact, sizeof(m->contact)))
return;
printf("Enter City: ");
if(!readLine(m->address.city,
sizeof(m->address.city)))
return;
m->address.pincode = 0;
m->history = NULL;
m->history_count = 0;
member_count++;
printf("Member Added Successfully\n");
}
/* Borrow a book */
void borrowBook(int memberID, int bookID)
{
    struct Member *m = NULL;
    struct Book *b = searchBook(bookID);
    for(size_t i = 0; i < member_count; i++)
    {
        if(members[i].member_id == memberID)
        {
            m = &members[i];
            break;
        }
}
if(m == NULL || b == NULL)
{
    printf("Member or Book Not Found\n");


    return;
}
if(!b->availability)
{
    printf("Book Already Borrowed\n");
    return;
}
struct Borrowing *temp =
realloc(m->history,
(m->history_count + 1) * sizeof(struct Borrowing));
if(temp == NULL)
{
    printf("Memory Allocation Failed\n");
    return;
}
m->history = temp;
struct Borrowing *h =
&m->history[m->history_count];
h->book_id = bookID;
printf("Enter Issue Date (DD-MM-YYYY): ");
if(!readLine(h->issue_date,
sizeof(h->issue_date)))
return;
h->returned = 0;
m->history_count++;
b->availability = 0;
printf("Borrowing Recorded Successfully\n");
}
/* Member summary */
void memberSummary(int id)
{
    struct Member *m = NULL;
    for(size_t i = 0; i < member_count; i++)
    {
        if(members[i].member_id == id)
        {
            m = &members[i];
            break;


        }
}
if(m == NULL)
{
    printf("Member Not Found\n");
    return;
}
printf("\nMEMBER BORROWING SUMMARY\n");
printf("Member ID: %d\n", m->member_id);
printf("Name: %s\n", m->name);
printf("City: %s\n", m->address.city);
printf("Total Borrowings: %zu\n",
m->history_count);
for(size_t i = 0; i < m->history_count; i++)
{
    printf("Book ID: %d\n",
    m->history[i].book_id);
    printf("Issue Date: %s\n",
    m->history[i].issue_date);
    printf("Status: %s\n",
    m->history[i].returned ?
    "Returned" : "Not Returned");
}
}
/* Memory cleanup */
void cleanup(void)
{
    for(size_t i = 0; i < member_count; i++)
    free(members[i].history);
    free(members);
    free(books);
    members = NULL;
    books = NULL;
}
/* Main */
int main(int argc, char *argv[])
{
    int id;
    if(argc < 2)
    {


        printf("Usage:\n");
        printf("./library add\n");
        printf("./library member\n");
        printf("./library list\n");
        printf("./library search <id>\n");
        printf("./library borrow <member_id> <book_id>\n");
        printf("./library summary <member_id>\n");
        return 1;
    }
if(strcmp(argv[1], "add") == 0)
addBook();
else if(strcmp(argv[1], "member") == 0)
addMember();
else if(strcmp(argv[1], "list") == 0)
listBooks();
else if(strcmp(argv[1], "search") == 0)
{
    if(argc != 3)
    printf("Invalid Arguments\n");
    else if(readInteger("Enter Search ID: ", &id))
    findBook(id);
    else
    printf("Invalid ID\n");
}
else if(strcmp(argv[1], "summary") == 0)
{
    if(argc != 3)
    printf("Invalid Arguments\n");
    else if(readInteger("Enter Member ID: ", &id))
    memberSummary(id);
    else
    printf("Invalid Member ID\n");
}
else if(strcmp(argv[1], "borrow") == 0)
{
    printf("Borrow operation requires both member and book IDs.\n");
    printf("Use the interactive extension in the complete implementation.\n");
}
else
printf("Invalid Command\n");
cleanup();


return 0;
}
