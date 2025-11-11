#include<stdio.h>
int main() {
    int i, marks[10], students, totalmarks=0, highestmark=-1, lowestmark=101, passed=0, failed=0;
    int gradeAplus=0, gradeA=0, gradeB=0, gradeC=0, gradeD=0, gradefail=0;
    float clsavg;

    printf("enter num of students(max 10): ");
    scanf("%d", &students);
    if(students <= 0 || students > 10) {
        printf("invalid enter number 1-10\n");
        return 1;
    }

    for(i=0; i<students; i++) {
        printf("marks of student %d= ", i+1);
        scanf("%d", &marks[i]);
        if(marks[i]<0 || marks[i]>100) {
            printf("invalid marks\n");
            return 1;
        }
        totalmarks += marks[i];
        if(marks[i] > highestmark) highestmark = marks[i];
        if(marks[i] < lowestmark) lowestmark = marks[i];

        if(marks[i]>=90) { gradeAplus++; passed++; }
        else if(marks[i]>=80) { gradeA++; passed++; }
        else if(marks[i]>=70) { gradeB++; passed++; }
        else if(marks[i]>=60) { gradeC++; passed++; }
        else if(marks[i]>=50) { gradeD++; passed++; }
        else { gradefail++; failed++; }
    }

    clsavg = (float)totalmarks / students;
    printf("\nsummary\n");
    printf("avg marks = %.2f\n", clsavg);
    printf("highest marks = %d\n", highestmark);
    printf("lowest marks = %d\n", lowestmark);
    printf("total passed = %d\n", passed);
    printf("failed = %d\n", failed);
    printf("\ngrade\n");
    printf("grade A+ = %d members\n", gradeAplus);
    printf("grade A = %d members\n", gradeA);
    printf("grade B = %d members\n", gradeB);
    printf("grade C = %d members\n", gradeC);
    printf("grade D = %d members\n", gradeD);
    printf("failed = %d members\n", gradefail);

    return 0;
}
