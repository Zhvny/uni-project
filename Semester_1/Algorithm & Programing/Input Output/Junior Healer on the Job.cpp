#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, H;
    scanf("%d %d", &N, &H);

    int matrix[N][N];
    int min_val = 10001, min_row = -1, min_col = -1;

    // Read the matrix and find the minimum value and its position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    // Heal the matrix based on the smallest element's row and column
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == min_row || j == min_col) {
                if (i == min_row && j == min_col) {
                    matrix[i][j] = min(H * H, 10000);  // Heal min value by H^2
                } else {
                    matrix[i][j] = min(matrix[i][j] + H, 10000);  // Heal by H
                }
            }
        }
    }

    // Print the healed matrix
    printf("ans: ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}

