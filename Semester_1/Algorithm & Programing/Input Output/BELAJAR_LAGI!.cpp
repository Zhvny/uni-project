#include <stdio.h>

int main() {
    char course_code[11][11]; // Store up to 10 characters for each course code
    char start_time[11][6], end_time[11][6]; // Time strings (HH:MM)

    // Read 5 lines of input
    for (int i = 0; i < 5; i++) {
        scanf("%s %5s-%5s", course_code[i], start_time[i], end_time[i]);
    }

    // Process and convert the times
    for (int i = 0; i < 5; i++) {
        // Convert start time
        start_time[i][0]--; // Decrease the hour by 1
        if (start_time[i][0] < '0') {
            start_time[i][0] = '2'; // Wrap around to 23
            start_time[i][1] = '3'; // Set hour to 23
        }

        // Convert end time
        end_time[i][0]--; // Decrease the hour by 1
        if (end_time[i][0] < '0') {
            end_time[i][0] = '2'; // Wrap around to 23
            end_time[i][1] = '3'; // Set hour to 23
        }

        // Print the updated schedule
        printf("%s %s-%s\n", course_code[i], start_time[i], end_time[i]);
    }

    return 0;
}

