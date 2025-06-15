#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A;
        scanf("%d", &A);

        double reaumur = (4.0 / 5.0) * A;  
        double fahrenheit = (9.0 / 5.0) * A + 32; 
        double kelvin = A + 273.0;

        // Print the results with 2 decimal places
        printf("%.2f %.2f %.2f\n", reaumur, fahrenheit, kelvin);
    }

    return 0;
}

