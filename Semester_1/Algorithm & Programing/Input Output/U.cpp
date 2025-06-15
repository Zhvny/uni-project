#include <stdio.h>

int main() {
    int T = 3;
    scanf("%d", &T);
    
    double A, B;
    double rotations;

    for (int i = 0; i < T; i++) {
        scanf("%lf %lf", &A, &B);

        rotations = (double)(A * B) / 360.0;

        printf("%.2lf\n", rotations);
    }

    return 0;
}

