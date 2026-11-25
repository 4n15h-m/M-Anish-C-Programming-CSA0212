#include <stdio.h>

int main()
{
    double units, rate, subtotal;

    printf("Enter Units Consumed: ");
    scanf("%lf", &units);

    printf("Enter Rate Per Unit: ");
    scanf("%lf", &rate);

    subtotal = units * rate;

    printf("Subtotal = Rs. %.2lf\n", subtotal);

    return 0;
}
