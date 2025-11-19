#include <stdio.h>
#include <stdlib.h>

#define max_vehicles 30
#define speed_limit 80
void read_vehicle_data(int vehicle_ids[], int speeds[], int lanes[], int *count);
int count_speed_violations(int speeds[], int count);
int count_lane_violations(int vehicle_ids[], int lanes[], int count, int *max_violation_index, int *max_violation_value);
int find_busiest_lane(int lanes[], int count);
int find_least_busy_lane(int lanes[], int count);
void print_traffic_report(int vehicle_ids[], int speeds[], int lanes[], int count);

int main() {
    int vehicle_ids[max_vehicles], speeds[max_vehicles], lanes[max_vehicles];
    int vehicle_count;
    int max_violation_index, max_violation_value;

    
    read_vehicle_data(vehicle_ids, speeds, lanes, &vehicle_count);

    
    int speed_violations = count_speed_violations(speeds, vehicle_count);
    printf("\nTotal number of speed violations: %d\n", speed_violations);

    
    int lane_violations = count_lane_violations(vehicle_ids, lanes, vehicle_count, &max_violation_index, &max_violation_value);
    printf("Total number of lane violations: %d\n", lane_violations);

    
    if (lane_violations > 0) {
        printf("Vehicle with the most severe lane violation: %d (Severity: %d)\n", vehicle_ids[max_violation_index], max_violation_value);
    } else {
        printf("No lane violations detected.\n");
    }

    
    printf("Busiest lane traffic volume: Lane %d\n", find_busiest_lane(lanes, vehicle_count));
    printf("Least busy lane traffic volume: Lane %d\n", find_least_busy_lane(lanes, vehicle_count));

    
    print_traffic_report(vehicle_ids, speeds, lanes, vehicle_count);

    return 0;
}


void read_vehicle_data(int vehicle_ids[], int speeds[], int lanes[], int *count) {
    printf("Enter number of vehicles (up to %d): ", max_vehicles);
    scanf("%d", count);

    for (int i = 0; i < *count; i++) {
        printf("\nVehicle %d details:\n", i + 1);

        
        do {
            printf("  Vehicle ID (4-digit number): ");
            scanf("%d", &vehicle_ids[i]);
        } while (vehicle_ids[i] < 1000 || vehicle_ids[i] > 9999);

        
        do {
            printf("  Speed (km/h, positive integer): ");
            scanf("%d", &speeds[i]);
        } while (speeds[i] <= 0);

        
        do {
            printf("  Lane number (1 to 4): ");
            scanf("%d", &lanes[i]);
        } while (lanes[i] < 1 || lanes[i] > 4);
    }
}

int count_speed_violations(int speeds[], int count) {
    int violation_count = 0;
    int highest_speed = speeds[0];
    int lowest_speed = speeds[0];

    for (int i = 0; i < count; i++) {
        if (speeds[i] > speed_limit) {
            violation_count++;
        }
        if (speeds[i] > highest_speed) {
            highest_speed = speeds[i];
        }
        if (speeds[i] < lowest_speed) {
            lowest_speed = speeds[i];
        }
    }
    printf("Highest speed recorded: %d km/h\n", highest_speed);
    printf("Lowest speed recorded: %d km/h\n", lowest_speed);

    return violation_count;
}

// Count lane violations and identify the vehicle with the most severe violation
int count_lane_violations(int vehicle_ids[], int lanes[], int count, int *max_violation_index, int *max_violation_value) {
    int violation_count = 0;
    *max_violation_value = 0;

    for (int i = 0; i < count; i++) {
        // Calculated expected lane based on vehicle ID modulo 4 rule
        int expected_lane = (vehicle_ids[i] % 4 == 0) ? 4 : (vehicle_ids[i] % 4);
        int violation_severity = abs(expected_lane - lanes[i]);

        if (expected_lane != lanes[i]) {
            violation_count++;
            if (violation_severity > *max_violation_value) {
                *max_violation_value = violation_severity;
                *max_violation_index = i;
            }
        }
    }

    return violation_count;
}

// Identify the busiest lane (most vehicles)
int find_busiest_lane(int lanes[], int count) {
    int lane_counts[4] = {0};

    for (int i = 0; i < count; i++) {
        lane_counts[lanes[i] - 1]++;
    }

    int busiest = 0;
    for (int i = 1; i < 4; i++) {
        if (lane_counts[i] > lane_counts[busiest]) {
            busiest = i;
        }
    }

    return busiest + 1;
}


int find_least_busy_lane(int lanes[], int count) {
    int lane_counts[4] = {0};

    for (int i = 0; i < count; i++) {
        lane_counts[lanes[i] - 1]++;
    }

    int least_busy = 0;
    for (int i = 1; i < 4; i++) {
        if (lane_counts[i] < lane_counts[least_busy]) {
            least_busy = i;
        }
    }

    return least_busy + 1;
}
void print_traffic_report(int vehicle_ids[], int speeds[], int lanes[], int count) {
    printf("\nVehicle Report:\n");
    printf("ID\tSpeed(km/h)\tLane\tSpeed Violation\tLane Violation\n");

    for (int i = 0; i < count; i++) {
        int speed_violation = (speeds[i] > speed_limit) ? 1 : 0;
        int expected_lane = (vehicle_ids[i] % 4 == 0) ? 4 : (vehicle_ids[i] % 4);
        int lane_violation = (expected_lane != lanes[i]) ? 1 : 0;

        printf("%d\t%d\t\t%d\t%d\t\t%d\n",
               vehicle_ids[i], speeds[i], lanes[i], speed_violation, lane_violation);
    }
}
