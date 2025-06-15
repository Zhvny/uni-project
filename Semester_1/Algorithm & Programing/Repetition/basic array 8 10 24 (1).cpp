#include <stdio.h>
#include <string.h>

int main() {
    char kata[50];
    scanf("%s", kata);

    int lenght = strlen(kata);
    for (int i = lenght - 1; i >= 0; i--) {
        printf("%c", kata[i]);
    }
}

