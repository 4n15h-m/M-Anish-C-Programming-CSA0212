#include <stdio.h>

int main()
{
    int i, mark[5] = {80, 90, -1, 70, 60};

    for(i = 0; i < 5; i++)
    {
        if(mark[i] < 0)
        {
            printf("Invalid record skipped\n");
            continue;
        }
        printf("Mark: %d\n", mark[i]);
    }

    return 0;
}
