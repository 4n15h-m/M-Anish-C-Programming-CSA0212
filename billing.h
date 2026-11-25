#ifndef BILLING_H
#define BILLING_H

#define SERVICE_PERCENT 5.0

double calculateSubtotal(double units, double rate);
double calculateService(double subtotal);

#endif
