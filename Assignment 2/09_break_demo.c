#include <stdio.h>

int main()
{
    int id[5] = {101, 102, 103, 104, 105};
    int key = 103, i;

    for(i = 0; i < 5; i++)
    {
        if(id[i] == key)
        {
            printf("Student Found");
            break;
        }
    }

    return 0;
}
