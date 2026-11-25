#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG
    printf("Debug Mode Enabled\n");
#endif
    printf("Billing System Running\n");
    return 0;
}
