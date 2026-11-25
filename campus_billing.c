#include <stdio.h>
#include <string.h>

#define SERVICE_PERCENT 5.0

int main(void)
{
    char facility_code[30];
    char consumer_name[50];
    int consumer_id;
    double units;
    double rate;
    double subtotal;
    double service_charge;
    double final_bill;

    printf("====================================\n");
    printf("  SMART CAMPUS UTILITY BILLING SYSTEM\n");
    printf("====================================\n");

    /* Facility Information */
    printf("Enter Facility Code: ");
    if(scanf("%29s", facility_code) != 1)
    {
        printf("Invalid Facility Code\n");
        return 1;
    }

    /* Consumer Information */
    printf("Enter Consumer ID: ");
    if(scanf("%d", &consumer_id) != 1 ||
       consumer_id <= 0)
    {
        printf("Invalid Consumer ID\n");
        return 1;
    }

    printf("Enter Consumer Name: ");
    if(scanf(" %49[^\n]", consumer_name) != 1)
    {
        printf("Invalid Consumer Name\n");
        return 1;
    }

    /* Utility Details */
    printf("Enter Units Consumed: ");
    if(scanf("%lf", &units) != 1 || units < 0)
    {
        printf("Invalid Units\n");
        return 1;
    }

    printf("Enter Rate Per Unit: ");
    if(scanf("%lf", &rate) != 1 || rate < 0)
    {
        printf("Invalid Rate\n");
        return 1;
    }

    /* Billing Calculations */
    subtotal = units * rate;
    service_charge = subtotal * SERVICE_PERCENT / 100.0;
    final_bill = subtotal + service_charge;

    /* Display Billing Summary */
    printf("\n====================================\n");
    printf("            BILL SUMMARY\n");
    printf("====================================\n");
    printf("Facility Code : %s\n", facility_code);
    printf("Consumer ID   : %d\n", consumer_id);
    printf("Consumer Name : %s\n", consumer_name);
    printf("Units         : %.2lf\n", units);
    printf("Rate          : Rs. %.2lf\n", rate);
    printf("------------------------------------\n");
    printf("Subtotal      : Rs. %.2lf\n", subtotal);
    printf("Service Charge: Rs. %.2lf\n", service_charge);
    printf("------------------------------------\n");
    printf("FINAL BILL    : Rs. %.2lf\n", final_bill);
    printf("====================================\n");

    return 0;
}
