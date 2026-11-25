#include <stdio.h>

#define SERVICE_PERCENT 5.0

int main()
{
    double units = 100;
    double rate = 8.0;
    double subtotal = units * rate;
    double service = subtotal * SERVICE_PERCENT / 100.0;

    printf("Subtotal: %.2lf\n", subtotal);
    printf("Service Charge: %.2lf\n", service);

    return 0;
}
