#include <stdio.h>

void display(int marks[][3], int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", marks[i][j]);
        printf("\n");
    }
}

int main()
{
    int marks[2][3] =
    {
        {80, 75, 90},
        {70, 85, 95}
    };

    display(marks, 2);
    return 0;
}
