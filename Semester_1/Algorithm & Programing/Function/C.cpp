#include <stdio.h>

int ackermann(int m, int n){ 
	if (m == 0) return n + 1; 
	if (m == 1) return n + 2; 
	if (m == 2) return 2 * n + 3; 
	if (m == 3) { 
	int result = 1; 
		for (int i = 0; i <= n; i++){ 
			result = 2 * result + 3;
			} 
			return result;
		}
		return -1; 
	}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int result = ackermann(m, n);
    printf("result: %d\n", result);

    return 0;
}
