# Day21_SmartcityTrafdicControl
**Student Name:** D.koushik
**Roll No:** AP25110090192
**Challenge:** Day 20 - Smart city traffic Control 

## Description
The program monitors traffic by recording each vehicle’s ID,
speed, and lane number.It checks for speed violations against
a fixed speed limit and finds the highest and lowest speeds.
Lane violations are detected by comparing actual vs expected 
lanes based on vehicle ID rules.It determines the busiest and
least busy lanes from gathered data.Finally, it prints a detailed 
report of all vehicles, showing both speed and lane violations.

## Build Commands
### Linux/macOS:
```bash
mkdir -p build
gcc -std=c11 -Wall -Wextra -O2 main.c -o build/program
