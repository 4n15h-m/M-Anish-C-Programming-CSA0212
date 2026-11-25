#include <stdio.h>

int calculateTotal(int marks[], int n);
float calculateAverage(int total, int n);
void displayResult(int id, int marks[], int n);

int main()
{
    int marks[] = {80, 75, 90};
    int id = 101;

    displayResult(id, marks, 3);

    return 0;
}

int calculateTotal(int marks[], int n)
{
    int i, total = 0;
    for(i = 0; i < n; i++)
        total += marks[i];
    return total;
}

float calculateAverage(int total, int n)
{
    return total / (float)n;
}

void displayResult(int id, int marks[], int n)
{
    int total;
    total = calculateTotal(marks, n);

    printf("Student ID: %d\n", id);
    printf("Total Marks: %d\n", total);
    printf("Average: %.2f\n", calculateAverage(total, n));
}
