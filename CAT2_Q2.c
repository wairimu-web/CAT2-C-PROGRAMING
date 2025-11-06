// hours worked and wages
#include <stdio.h>

int main() {
    float hours, wage, gross_pay, taxes, net_pay;

    // Input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &wage);

    // Calculate gross pay (with overtime)
    if (hours <= 40) {
        gross_pay = hours * wage;
    } else {
        gross_pay = (40 * wage) + ((hours - 40) * wage * 1.5);
    }

    // Calculate taxes
    if (gross_pay <= 600) {
        taxes = 0.15 * gross_pay;
    } else {
        taxes = (0.15 * 600) + (0.20 * (gross_pay - 600));
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Output results
    printf("\n--- Pay Summary ---\n");
    printf("Gross pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", net_pay);

 return 0;
}