#include <stdio.h>
int main() 
{
    int attendance[5][5], marks[5][5];
    char names[5][20];
    int i, j, option;

    //student names
    printf("Input names of 5 students:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Name of student %d: ", i + 1);
        scanf("%19s", names[i]);
    }

    //attendance
    printf("\nRecord attendance (1=Present, 0=Absent):\n");
    for (i = 0; i < 5; i++) 
    {
        printf("Attendance for %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &attendance[i][j]);
        }
    }

    //marks 
    printf("\nRecord marks (0-100):\n");
    for (i = 0; i < 5; i++) {
        printf("Marks for %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    do {
        printf("\n====== STUDENT DATA MENU ======\n");
        printf("1. Show Attendance Table\n");
        printf("2. Show Marks Table\n");
        printf("3. Generate Attendance Summary\n");
        printf("4. Generate Performance Summary\n");
        printf("5. Show Grade Report\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 1) 
        {
            printf("\nAttendance Matrix:\n");
            for (i = 0; i < 5; i++) 
            {
                printf("%-15s", names[i]);
                for (j = 0; j < 5; j++) 
                {
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        } else if (option == 2) 
        {
            printf("\nMarks Matrix:\n");
            for (i = 0; i < 5; i++) 
            {
                printf("%-15s", names[i]);
                for (j = 0; j < 5; j++) 
                {
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        } 
        else if (option == 3) 
        {
            int presentCount[5] = {0}, absentCount[5] = {0};
            int highestPresence = -1, lowestPresence = 6;
            int maxInd = 0, minInd = 0;

            for (i = 0; i < 5; i++) 
            {
                int totalPresent = 0;
                for (j = 0; j < 5; j++) 
                {
                    totalPresent += attendance[i][j];
                }
                presentCount[i] = totalPresent;
                absentCount[i] = 5 - totalPresent;

                if (totalPresent > highestPresence) 
                {
                    highestPresence = totalPresent;
                    maxInd = i;
                }
                if (totalPresent < lowestPresence) 
                {
                    lowestPresence = totalPresent;
                    minInd = i;
                }
            }

            printf("\nAttendance Summary:\n");
            for (i = 0; i < 5; i++) 
            {
                printf("%-15s Present: %d, Absent: %d\n", names[i], presentCount[i], absentCount[i]);
            }
            printf("Top Attendance: %s with %d classes present\n", names[maxInd], highestPresence);
            printf("Lowest Attendance: %s with %d classes present\n", names[minInd], lowestPresence);

        } 
        else if (option == 4) 
        {
            int totals[5] = {0};
            float averages[5];
            int highestTotal = -1, lowestTotal = 501;
            int topperIdx = 0, lowestIdx = 0;

            for (i = 0; i < 5; i++) 
            {
                int totalScore = 0;
                for (j = 0; j < 5; j++) 
                {
                    totalScore += marks[i][j];
                }
                totals[i] = totalScore;
                averages[i] = totalScore / 5.0f;

                if (totalScore > highestTotal) 
                {
                    highestTotal = totalScore;
                    topperIdx = i;
                }
                if (totalScore < lowestTotal) 
                {
                    lowestTotal = totalScore;
                    lowestIdx = i;
                }
            }

            printf("\nPerformance Summary:\n");
            for (i = 0; i < 5; i++) {
                printf("%-15s Total: %d, Average: %.2f\n", names[i], totals[i], averages[i]);
            }
            printf("Topper: %s with %d total marks\n", names[topperIdx], highestTotal);
            printf("Lowest Performer: %s with %d total marks\n", names[lowestIdx], lowestTotal);

        } 
        else if (option == 5) 
        {
            printf("\nGrade Report:\n");
            for (i = 0; i < 5; i++) 
            {
                int sumMarks = 0;
                for (j = 0; j < 5; j++) 
                {
                    sumMarks += marks[i][j];
                }
                float avg = sumMarks / 5.0f;
                char grade;

                if (avg >= 90) 
                {
                    grade = 'A'; // A+ treated as A for being simple
                    printf("%-15s Average: %.2f, Grade: A+\n", names[i], avg);
                } 
                else if (avg >= 80) 
                {
                    grade = 'A';
                    printf("%-15s Average: %.2f, Grade: A\n", names[i], avg);
                } 
                else if (avg >= 70) 
                {
                    grade = 'B';
                    printf("%-15s Average: %.2f, Grade: B\n", names[i], avg);
                }
                 else if (avg >= 60) 
                {
                    grade = 'C';
                    printf("%-15s Average: %.2f, Grade: C\n", names[i], avg);
                }
                 else if (avg >= 50) 
                {
                    grade = 'D';
                    printf("%-15s Average: %.2f, Grade: D\n", names[i], avg);
                } 
                else 
                {
                    grade = 'F';
                    printf("%-15s Average: %.2f, Grade: F\n", names[i], avg);
                }
            }
        }
         else if (option == 6) 
        {
            printf("Program terminated. Have a nice day!\n");
        } 
        else 
        {
            printf("Invalid option. Try again.\n");
        }

    } 
    while (option != 6);

    return 0;
}
