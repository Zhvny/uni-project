#include <stdio.h>

int n;
void displaySumLeaves(int x, int a[], int sum) {
    sum += a[x];
    int left = 2 * x;
    int right = 2 * x + 1;

    if (left <= n) {
        displaySumLeaves(left, a, sum);
        if (right <= n) {
            displaySumLeaves(right, a, sum);
        }
    }

    else {
        printf("%d\n", sum);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);

		int a[n + 1]; // index dari 1
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
        }
    printf("Case #%d:\n", i + 1);    
    displaySumLeaves(1, a, 0);
    }
    return 0;
}

// 3 7 1 2 3 4 5 6 7 5 1 2 3 4 5 2 3 3


