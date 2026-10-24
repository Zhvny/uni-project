#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define alphabet 26
#define maxWord 100
#define maxDesc 1000

typedef struct Node {
    struct Node* children[alphabet];
    char* desc;
    bool endOfWord;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        for (int i = 0; i < alphabet; i++) {
            newNode->children[i] = NULL;
        }
        newNode->desc = NULL;
        newNode->endOfWord = false;
    }
    return newNode;
}

bool validSlang(const char* word) {
    if (strlen(word) <= 1) {
        return false;
    }
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (isspace(word[i])) {
            return false;
        }
    }
    
    return true;
}

bool validDesc(const char* desc) {
    int wordCount = 0;
    bool inWord = false;
    
    for (int i = 0; desc[i] != '\0'; i++) {
        if (isspace(desc[i])) {
            if (inWord) {
                inWord = false;
            }
        } else {
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        }
    }
    
    return wordCount > 1;
}

bool insertWord(Node* root, const char* word, const char* desc) {
    Node* current = root;
    bool isNewWord = false;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        
        if (index < 0 || index >= alphabet) {
            continue;
        }
        
        if (!current->children[index]) {
            current->children[index] = createNode();
            isNewWord = true;
        }
        
        current = current->children[index];
    }
    
    if (current->endOfWord) {
        free(current->desc);
        isNewWord = false;
    }
    
    current->desc = strdup(desc);
    current->endOfWord = true;
    
    return isNewWord;
}

Node* searchWord(Node* root, const char* word) {
    Node* current = root;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        
        if (index < 0 || index >= alphabet) {
            return NULL;
        }
        
        if (!current->children[index]) {
            return NULL;
        }
        
        current = current->children[index];
    }
    
    if (current && current->endOfWord) {
        return current;
    }
    
    return NULL;
}

void findAllWithPrefix(Node* root, char* prefix, char* buffer, int depth, char** wordList, int* wordCount) {
    if (!root) {
        return;
    }
    
    if (root->endOfWord) {
        buffer[depth] = '\0';
        wordList[(*wordCount)] = strdup(buffer);
        (*wordCount)++;
    }
    
    for (int i = 0; i < alphabet; i++) {
        if (root->children[i]) {
            buffer[depth] = 'a' + i;
            findAllWithPrefix(root->children[i], prefix, buffer, depth + 1, wordList, wordCount);
        }
    }
}

void storeAllWord(Node* root, char* buffer, int depth, char** wordList, int* wordCount) {
    if (!root) {
        return;
    }
    
    if (root->endOfWord) {
        buffer[depth] = '\0';
        wordList[(*wordCount)] = strdup(buffer);
        (*wordCount)++;
    }
    
    for (int i = 0; i < alphabet; i++) {
        if (root->children[i]) {
            buffer[depth] = 'a' + i;
            storeAllWord(root->children[i], buffer, depth + 1, wordList, wordCount);
        }
    }
}

bool displayWordWithPrefix(Node* root, const char* prefix) {
    Node* current = root;
    
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = tolower(prefix[i]) - 'a';
        
        if (index < 0 || index >= alphabet) {
            return false;
        }
        
        if (!current->children[index]) {
            return false;
        }
        
        current = current->children[index];
    }
    
    char** wordList = (char**)malloc(1000 * sizeof(char*));
    int wordCount = 0;
    
    char buffer[maxWord];
    strcpy(buffer, prefix);
    
    findAllWithPrefix(current, (char*)prefix, buffer, strlen(prefix), wordList, &wordCount);
    
    if (wordCount == 0) {
        free(wordList);
        return false;
    }
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(wordList[i], wordList[j]) > 0) {
                char* temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
    
    printf("\nWords starts with \"%s\":\n\n", prefix);
    for (int i = 0; i < wordCount; i++) {
        printf("%d. %s\n\n", i + 1, wordList[i]);
    }
    
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i]);
    }
    free(wordList);
    
    return true;
}

bool displayAllWord(Node* root) {
    char** wordList = (char**)malloc(1000 * sizeof(char*));
    int wordCount = 0;
    
    char buffer[maxWord] = {0};
    
    storeAllWord(root, buffer, 0, wordList, &wordCount);
    
    if (wordCount == 0) {
        free(wordList);
        return false;
    }
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(wordList[i], wordList[j]) > 0) {
                char* temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
    
    printf("\nList of all slang words in the dictionary:\n\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d. %s\n\n", i + 1, wordList[i]);
    }
    
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i]);
    }
    free(wordList);
    
    return true;
}

void freeTrie(Node* root) {
    if (!root) {
        return;
    }
    
    for (int i = 0; i < alphabet; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    
    if (root->desc) {
        free(root->desc);
    }
    
    free(root);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Node* root = createNode();
    int choice;
    
    do {
        printf("\n===== Boogle - Slang Word Dictionary =====\n");
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix word\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        char word[maxWord];
        char desc[maxDesc];
        Node* searchResult;
        
        switch (choice) {
            case 1:
                do {
                    printf("\nInput a new slang word [Must be more than 1 characters and contains no space]: ");
                    fgets(word, maxWord, stdin);
                    word[strcspn(word, "\n")] = '\0';
                } while (!validSlang(word));
                
                do {
                    printf("\nInput a new slang word desc [Must be more than 2 words]: ");
                    fgets(desc, maxDesc, stdin);
                    desc[strcspn(desc, "\n")] = '\0';
                } while (!validDesc(desc));
                
                if (insertWord(root, word, desc)) {
                    printf("\nSuccessfully released new slang word.\n");
                } else {
                    printf("\nSuccessfully updated a slang word.\n");
                }
                
                printf("\nPress enter to continue...");
                getchar();
                break;
                
            case 2:
                do {
                    printf("\nInput a slang word to be searched [Must be more than 1 characters and contains no space]: ");
                    fgets(word, maxWord, stdin);
                    word[strcspn(word, "\n")] = '\0';
                } while (!validSlang(word));
                
                searchResult = searchWord(root, word);
                if (searchResult) {
                    printf("\nSlang word : %s\n\n", word);
                    printf("Description : %s\n", searchResult->desc);
                } else {
                    printf("\nThere is no word \"%s\" in the dictionary.\n", word);
                }
                
                printf("\nPress enter to continue...");
                getchar();
                break;
                
            case 3:
                printf("\nInput a prefix to be searched: ");
                fgets(word, maxWord, stdin);
                word[strcspn(word, "\n")] = '\0';
                
                if (!displayWordWithPrefix(root, word)) {
                    printf("\nThere is no prefix \"%s\" in the dictionary.\n", word);
                }
                
                printf("\nPress enter to continue...");
                getchar();
                break;
                
            case 4:
                if (!displayAllWord(root)) {
                    printf("\nThere is no slang word yet in the dictionary.\n");
                }
                
                printf("\nPress enter to continue...");
                getchar();
                break;
                
            case 5:
                printf("\nThank you... Have a nice day :)\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
                printf("\nPress enter to continue...");
                getchar();
        }
    } while (choice != 5);
    
    freeTrie(root);
    
    return 0;
}
