#include <stdio.h>
#define N 4

int main()
{
    int id[N] = {101, 102, 103, 104};
    int total[N] = {240, 210, 270, 230};
    int i, j, temp;

    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - i - 1; j++)
        {
            if(total[j] < total[j + 1])
            {
                temp = total[j];
                total[j] = total[j + 1];
                total[j + 1] = temp;

                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }

    printf("STUDENT RANKING\n");
    for(i = 0; i < N; i++)
    {
        printf("Student ID: %d | Total: %d\n", id[i], total[i]);
    }

    return 0;
}
