#include <stdio.h>

int main() {
    int n1, n2, n3;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    printf("%d\n", (n1 / 10) % 10);
    printf("%d\n", (n2 / 10) % 10);
    printf("%d\n", (n3 / 10) % 10);

    return 0;
}
	
