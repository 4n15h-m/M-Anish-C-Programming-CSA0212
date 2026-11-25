#include <stdio.h>

int main()
{
    int A[] = {210, 230, 240, 270};
    int B[] = {220, 230, 250, 280};
    int C[8];
    int i = 0, j = 0, k = 0;

    while(i < 4 && j < 4)
    {
        if(A[i] <= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while(i < 4)
        C[k++] = A[i++];

    while(j < 4)
        C[k++] = B[j++];

    printf("Merged Array:\n");
    for(i = 0; i < 8; i++)
        printf("%d ", C[i]);
    printf("\n");

    return 0;
}
