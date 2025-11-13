#include <stdio.h>

int main() {
    char studentName[50], rollNum[20], classSection[5];
    int employeeCount, i, j, userOption;
    float payList[10];
    float sum = 0, mean = 0, maxSalary, minSalary;
    int aboveavg = 0, belowavg = 0;
    float swap;

    
    printf("- - - - - - - - -- -- - -- - - - - - - -- - - \n");
    printf("       Staff Salary Tracking Application       \n");
    printf("- - - - - - - -- -- - -  - - - - - - - - - -- - \n");

    
    printf("\nLet’s collect your details first:\n");
    printf("→ Your Name: ");
    scanf(" %[^\n]", studentName);
    printf("→ Roll Number: ");
    scanf(" %[^\n]", rollNum);
    printf("→ Section: ");
    scanf(" %[^\n]", classSection);

    
    printf("\nHow many employees do you want to track? (up to 10): ");
    scanf("%d", &employeeCount);
    if (employeeCount < 1 || employeeCount > 10) {
        printf("\nOops! Please make sure the number is between 1 and 10.\n");
        return 0;
    }

    printf("\nEnter the monthly salary for each staff member:\n");
    for (i = 0; i < employeeCount; i++) {
        printf(" Staff Member %d Salary: ₹", i + 1);
        scanf("%f", &payList[i]);
    }

    
    do {
        printf("\n_____________________________________________\n");
        printf("                 MAIN MENU                    \n");
        printf("_________________________________________________\n");
        printf("1 - Show All Staff Salaries\n");
        printf("2 - Show Total & Average Salary\n");
        printf("3 - Identify Highest & Lowest Salary\n");
        printf("4 - Employees Above/Below Average\n");
        printf("5 - Arrange Salaries (Lowest to Highest)\n");
        printf("6 - Quit\n");
        printf("=                                    = \n");
        printf("Pick an option (1–6): ");
        scanf("%d", &userOption);

        
        sum = 0;
        for (i = 0; i < employeeCount; i++) {
            sum += payList[i];
        }
        mean = sum / employeeCount;

        switch (userOption) {
            case 1:
                printf("\nAll Salaries of Staff:\n");
                for (i = 0; i < employeeCount; i++)
                    printf(" Staff %d: ₹%.2f\n", i + 1, payList[i]);
                break;
            case 2:
                printf("\nTotal Salary Paid: ₹%.2f\n", sum);
                printf("Average Salary: ₹%.2f\n", mean);
                break;
            case 3:
                maxSalary = minSalary = payList[0];
                for (i = 1; i < employeeCount; i++) {
                    if (payList[i] > maxSalary)
                        maxSalary = payList[i];
                    if (payList[i] < minSalary)
                        minSalary = payList[i];
                }
                printf("\nHighest Salary: ₹%.2f\n", maxSalary);
                printf("Lowest Salary: ₹%.2f\n", minSalary);
                break;
            case 4:
                aboveavg = belowavg = 0;
                for (i = 0; i < employeeCount; i++) {
                    if (payList[i] > mean)
                        aboveavg++;
                    else if (payList[i] < mean)
                        belowavg++;
                }
                printf("\nNumber Above Average: %d\n", aboveavg);
                printf("Number Below Average: %d\n", belowavg);
                break;
            case 5:
                
                for (i = 0; i < employeeCount - 1; i++) {
                    for (j = 0; j < employeeCount - i - 1; j++) {
                        if (payList[j] > payList[j + 1]) {
                            swap = payList[j];
                            payList[j] = payList[j + 1];
                            payList[j + 1] = swap;
                        }
                    }
                }
                printf("\nSalaries Sorted (Ascending):\n");
                for (i = 0; i < employeeCount; i++)
                    printf(" %.2f ", payList[i]);
                printf("\n");
                break;
            case 6:
                printf("\nGoodbye! Thanks for using the Salary Tracker.\n");
                break;
            default:
                printf("\nInvalid input. Please choose from 1–6.\n");
        }

        if (userOption != 6) {
            printf("\n----------------------------------------------\n");
            printf("By: %s | Roll: %s | Class: %s\n", studentName, rollNum, classSection);
            printf("----------------------------------------------\n");
        }
    } while (userOption != 6);

    printf("\nSystem closed.\n");
    printf("Submitted by: %s | Roll: %s | Section: %s\n", studentName, rollNum, classSection);
    printf("Challenge Day 17 – Code2Grow Program\n");

    return 0;
}
