#include <stdio.h>

/* Type 1: No arguments, no return value */
void display()
{
    printf("Examination Result System\n");
}

/* Type 2: Arguments, no return value */
void displayMarks(int marks)
{
    printf("Marks = %d\n", marks);
}

/* Type 3: No arguments, returns a value */
int getMarks()
{
    return 85;
}

/* Type 4: Arguments and returns a value */
int calculateTotal(int a, int b)
{
    return a + b;
}

int main()
{
    display();
    displayMarks(90);
    printf("getMarks() = %d\n", getMarks());
    printf("calculateTotal(80, 75) = %d\n", calculateTotal(80, 75));
    return 0;
}
