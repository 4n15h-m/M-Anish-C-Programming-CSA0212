#include <stdio.h>

int maximum(int a[], int n)
{
    int max;

    if(n == 1)
        return a[0];

    max = maximum(a, n - 1);

    if(a[n - 1] > max)
        return a[n - 1];

    return max;
}

int main()
{
    int marks[] = {80, 75, 90, 85};
    printf("Highest Mark = %d\n", maximum(marks, 4));
    return 0;
}
