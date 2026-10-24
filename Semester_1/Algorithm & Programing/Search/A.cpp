#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct {
    char shortW[SIZE];
    char oriW[SIZE];
} Kamus;

void translate_sentence(char *sentence, Kamus *kamus, int dictSize) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        int low = 0, high = dictSize - 1, found = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int cmp = strcmp(word, kamus[mid].shortW);
            if (cmp == 0) {
                printf("%s ", kamus[mid].oriW);
                found = 1;
                break;
            } else if (cmp < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (!found) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    int T, TC;
    Kamus kamus[SIZE];
    char sentences[SIZE][SIZE];

    FILE *file = fopen("testdata.in", "r");

    fscanf(file, "%d", &T);
    for (int i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%s\n", kamus[i].shortW, kamus[i].oriW);
    }

    for (int i = 0; i < T - 1; i++) {
        for (int j = 0; j < T - i - 1; j++) {
            if (strcmp(kamus[j].shortW, kamus[j + 1].shortW) > 0) {
                Kamus temp = kamus[j];
                kamus[j] = kamus[j + 1];
                kamus[j + 1] = temp;
            }
        }
    }

    fscanf(file, "%d\n", &TC);
    for (int i = 0; i < TC; i++) {
        fgets(sentences[i], SIZE, file);
        sentences[i][strcspn(sentences[i], "\n")] = '\0';
    }

    fclose(file);

    for (int i = 0; i < TC; i++) {
        printf("Case #%d:\n", i + 1);
        translate_sentence(sentences[i], kamus, T);
        printf("\n");
    }

    return 0;
}

