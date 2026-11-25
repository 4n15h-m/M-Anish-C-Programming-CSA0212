#include <stdio.h>

void calculate(int marks[], int n,
               int *total, float *average)
{
    int i;
    *total = 0;

    for(i = 0; i < n; i++)
        *total += marks[i];

    *average = *total / (float)n;
}

int main()
{
    int marks[] = {80, 75, 90};
    int total;
    float average;

    calculate(marks, 3, &total, &average);

    printf("Total = %d\n", total);
    printf("Average = %.2f\n", average);

    return 0;
}
