#include <stdio.h>

int main() {
    char names[2][105];
    double heights[2];
    int ages[2];

    scanf("%s %lf %d %s %lf %d", names[0], &heights[0], &ages[0], names[1], &heights[1], &ages[1]);

    printf("Name 1: %s\n", names[0]);
    printf("Height 1: %.2f\n", heights[0]);
    printf("Age 1: %d\n", ages[0]);

    printf("Name 2: %s\n", names[1]);
    printf("Height 2: %.2f\n", heights[1]);
    printf("Age 2: %d\n", ages[1]);

    return 0;
}

