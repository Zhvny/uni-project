#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct {
    char id[SIZE];
    char name[SIZE];
} Siswa;

int binary_search(Siswa siswa[], int left, int right, char searchID[]) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(siswa[mid].id, searchID);
        
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    FILE *file = fopen("testdata_b.in", "r");

    int N, T, i;
    Siswa siswa[SIZE];
    char searchID[11];

    fscanf(file, "%d", &N);
    for (i = 0; i < N; i++) {
        fscanf(file, "%s %s", siswa[i].id, siswa[i].name);
    }

    fscanf(file, "%d", &T);
    for (i = 1; i <= T; i++) {
        fscanf(file, "%s", searchID);
        int index = binary_search(siswa, 0, N - 1, searchID);
        if (index != -1) {
            printf("Case #%d: %s\n", i, siswa[index].name);
        } else {
            printf("Case #%d: N/A\n", i);
        }
    }

    fclose(file);
    return 0;
}
