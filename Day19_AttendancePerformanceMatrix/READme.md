# Day19_AttendencePerformanceMatrix
*Student Name:* digamarthi koushik
*Roll No:* AP25110090192
*Challenge:* Day 19 - Attendence Performence  Matrix

## Description
This C program manages basic student records for 5 students.
It stores names, attendance (for 5 subjects), and marks.
The user can choose options from a menu to view attendance or marks tables.
It also generates attendance and performance summaries along with grades.
Finally, it identifies top and lowest performers before exiting.

---

## Build Commands
### Linux/macOS:
```bash
mkdir -p build
gcc -std=c11 -Wall -Wextra -O2 main.c -o build/program

Input names of 5 students:
Name of student 1: koushik
Name of student 2: nanda 
Name of student 3: rahul
Name of student 4: aditya
Name of student 5: raju

Record attendance (1=Present, 0=Absent):
Attendance for koushik:
  Subject 1: 1
  Subject 2: 1
  Subject 3: 1
  Subject 4: 0
  Subject 5: 1
Attendance for nanda:
  Subject 1: 1
  Subject 2: 1
  Subject 3: 1
  Subject 4: 1
  Subject 5: 0
Attendance for rahul:
  Subject 1: 1
  Subject 2: 1
  Subject 3: 1
  Subject 4: 1
  Subject 5: 11
Attendance for aditya:
  Subject 1: 1
  Subject 2: 1
  Subject 3: 10
  Subject 4: 0
  Subject 5: 0
Attendance for raju:
  Subject 1: 1
  Subject 2: 1
  Subject 3: 1
  Subject 4: 1
  Subject 5: 1

Record marks (0-100):
Marks for koushik:
  Subject 1: 60
  Subject 2: 70
  Subject 3: 80
  Subject 4: 90
  Subject 5: 50
Marks for nanda:
  Subject 1: 40
  Subject 2: 50
  Subject 3: 60
  Subject 4: 70
  Subject 5: 80
Marks for rahul:
  Subject 1: 60
  Subject 2: 60
  Subject 3: 70
  Subject 4: 80
  Subject 5: 90
Marks for aditya:
  Subject 1: 60
  Subject 2: 70
  Subject 3: 70
  Subject 4: 70
  Subject 5: 80
Marks for raju:
  Subject 1: 80
  Subject 2: 80
  Subject 3: 70
  Subject 4: 60
  Subject 5: 85

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 1

Attendance Matrix:
koushik        1 1 1 0 1
nanda          1 1 1 1 0
rahul          1 1 1 1 11
aditya         1 1 10 0 0
raju           1 1 1 1 1

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 2

Marks Matrix:
koushik        60 70 80 90 50
nanda          40 50 60 70 80
rahul          60 60 70 80 90
aditya         60 70 70 70 80
raju           80 80 70 60 85

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 3

Attendance Summary:
koushik         Present: 4, Absent: 1
nanda           Present: 4, Absent: 1
rahul           Present: 15, Absent: -10
aditya          Present: 12, Absent: -7
raju            Present: 5, Absent: 0
Top Attendance: rahul with 15 classes present
Lowest Attendance: koushik with 4 classes present

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 4

Performance Summary:
koushik         Total: 350, Average: 70.00
nanda           Total: 300, Average: 60.00
rahul           Total: 360, Average: 72.00
aditya          Total: 350, Average: 70.00
raju            Total: 375, Average: 75.00
Topper: raju with 375 total marks
Lowest Performer: nanda with 300 total marks

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 5

Grade Report:
koushik         Average: 70.00, Grade: B
nanda           Average: 60.00, Grade: C
rahul           Average: 72.00, Grade: B
aditya          Average: 70.00, Grade: B
raju            Average: 75.00, Grade: B

====== STUDENT DATA MENU ======
1. Show Attendance Table
2. Show Marks Table
3. Generate Attendance Summary
4. Generate Performance Summary
5. Show Grade Report
6. Exit
Select an option: 6
Program terminated. Have a nice day!
