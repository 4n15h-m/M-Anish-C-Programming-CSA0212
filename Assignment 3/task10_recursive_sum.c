#include <stdio.h>

int sum(int a[], int n)
{
    if(n == 0)
        return 0;
    return a[n - 1] + sum(a, n - 1);
}

int main()
{
    int marks[] = {80, 75, 90, 85};
    printf("Total Marks = %d\n", sum(marks, 4));
    return 0;
}
