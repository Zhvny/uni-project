    #include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N;
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

//        int temp = 0;
//        for (int i = 0; i < N - 1; i++) {
//            for (int j = 0; j < N - i - 1; j++) {
//                if(A[j] > A[j + 1]) {
//                    temp = A[j];
//                    A[j] = A[j + 1];
//                    A[j + 1] = temp;
//                }
//            }
//        }

        int max = 0;
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > max) {
                max = A[i];
                count = 0;
            }
            
            else if (A[i] == max) {
            	count++;
			}
        }
        printf("Case #%d: %d\n", i + 1, count + 1);
    }
    return 0;
}

//   2 5 1 2 3 4 4 3 1 12 8
