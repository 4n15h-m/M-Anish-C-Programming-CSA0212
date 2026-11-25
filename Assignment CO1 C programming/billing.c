#include <stdio.h>
#include "billing.h"

double calculateSubtotal(double units, double rate)
{
    return units * rate;
}

double calculateService(double subtotal)
{
    return subtotal * SERVICE_PERCENT / 100.0;
}
