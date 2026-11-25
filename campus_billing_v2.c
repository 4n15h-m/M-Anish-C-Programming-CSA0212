#include <stdio.h>
#include <string.h>

#define SERVICE_PERCENT 5.0
#define CONCESSION_PERCENT 10.0
#define WARNING_LIMIT 1000.0

int main(void)
{
    char facility_code[30];
    char consumer_name[50];
    char department_code[20];
    int consumer_id;
    double units;
    double rate;
    double subtotal;
    double service_charge;
    double gross_bill;
    double concession;
    double final_bill;

    printf("SMART CAMPUS UTILITY BILLING SYSTEM\n");

    printf("Enter Facility Code: ");
    if(scanf("%29s", facility_code) != 1)
        return 1;

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
        printf("Invalid Name\n");
        return 1;
    }

    printf("Enter Department Code: ");
    if(scanf("%19s", department_code) != 1)
    {
        printf("Invalid Department Code\n");
        return 1;
    }

    printf("Enter Units: ");
    if(scanf("%lf", &units) != 1 || units < 0)
    {
        printf("Invalid Units\n");
        return 1;
    }

    printf("Enter Rate: ");
    if(scanf("%lf", &rate) != 1 || rate < 0)
    {
        printf("Invalid Rate\n");
        return 1;
    }

    /* Calculate Subtotal */
    subtotal = units * rate;

    /* Calculate Service Charge */
    service_charge = subtotal * SERVICE_PERCENT / 100.0;

    /* Calculate Gross Bill */
    gross_bill = subtotal + service_charge;

    /* Determine Concession */
    if(strcmp(department_code, "AID") == 0)
    {
        concession = subtotal * CONCESSION_PERCENT / 100.0;
    }
    else
    {
        concession = 0.0;
    }

    /* Calculate Final Bill */
    final_bill = gross_bill - concession;

    /* Display Summary */
    printf("\n========== BILL SUMMARY ==========\n");
    printf("Facility Code : %s\n", facility_code);
    printf("Consumer ID   : %d\n", consumer_id);
    printf("Consumer Name : %s\n", consumer_name);
    printf("Department    : %s\n", department_code);
    printf("Subtotal      : Rs. %.2lf\n", subtotal);
    printf("Service Charge: Rs. %.2lf\n", service_charge);
    printf("Concession    : Rs. %.2lf\n", concession);
    printf("Final Bill    : Rs. %.2lf\n", final_bill);

    if(final_bill > WARNING_LIMIT)
    {
        printf("WARNING: BILL EXCEEDS LIMIT!\n");
    }
    else
    {
        printf("Bill Within Warning Limit\n");
    }

    printf("==================================\n");

    return 0;
}
