#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int hasil = 0;

    for (int i = 1; i <= N; i++) {
        int A1;
        scanf("%d", &A1);
        hasil += A1;
    }
    printf("%d\n", hasil);

    return 0;
}
